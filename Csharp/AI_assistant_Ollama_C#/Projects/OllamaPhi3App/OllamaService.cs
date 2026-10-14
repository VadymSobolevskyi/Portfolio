using System;
using System.Net.Http;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;

namespace OllamaPhi3App
{
    public class OllamaService
    {
        private readonly HttpClient _httpClient;

        public OllamaService()
        {
            _httpClient = new HttpClient
            {
                BaseAddress = new Uri(Config.BaseUrl)
            };
        }

        public async Task<string?> GenerateTextAsync(string prompt)
        {
            var requestData = new
            {
                model = Config.ModelName,
                prompt = prompt,
                stream = false
            };

            var jsonContent = new StringContent(
                JsonSerializer.Serialize(requestData),
                Encoding.UTF8,
                "application/json"
            );

            try
            {
                HttpResponseMessage response = await _httpClient.PostAsync("/api/generate", jsonContent);
                response.EnsureSuccessStatusCode();

                string responseString = await response.Content.ReadAsStringAsync();

                return ExtractResponseText(responseString);
            }
            catch (HttpRequestException ex)
            {
                throw new Exception($"Помилка підключення до Ollama. Переконайтеся, що сервер запущено. Деталі: {ex.Message}");
            }
        }

        private string? ExtractResponseText(string jsonResponse)
        {
            using JsonDocument doc = JsonDocument.Parse(jsonResponse);
            JsonElement root = doc.RootElement;

            if (root.TryGetProperty("response", out JsonElement responseElement))
            {
                return responseElement.GetString();
            }

            return null;
        }
    }
}