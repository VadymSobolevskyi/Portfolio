using System.Net.Http.Json;
using System.Text;
using OllamaAssistant.Models;

namespace OllamaAssistant.Services;

public class OllamaService
{
    private readonly HttpClient _httpClient;

    private const string OllamaUrl =
        "http://localhost:11434/api/generate";

    private const string Model = "phi3";

    private const string SystemPrompt = """
        Ти — корисний AI-помічник.

        Відповідай зрозуміло, точно та по суті.
        Якщо користувач пише українською — відповідай українською.
        Якщо користувач пише англійською — відповідай англійською.
        Використовуй контекст попереднього діалогу.
        """;

    public OllamaService()
    {
        _httpClient = new HttpClient
        {
            Timeout = TimeSpan.FromMinutes(5)
        };
    }

    public async Task<string> GenerateResponseAsync(
        List<ChatMessage> conversation)
    {
        string prompt = BuildPrompt(conversation);

        var request = new OllamaRequest
        {
            Model = Model,
            Prompt = prompt,
            Stream = false,
            Options = new OllamaOptions
            {
                Temperature = 0.7
            }
        };

        HttpResponseMessage response =
            await _httpClient.PostAsJsonAsync(
                OllamaUrl,
                request);

        response.EnsureSuccessStatusCode();

        OllamaResponse? result =
            await response.Content.ReadFromJsonAsync<OllamaResponse>();

        if (result == null)
        {
            throw new Exception(
                "Ollama повернула порожню відповідь.");
        }

        return result.Response.Trim();
    }

    private static string BuildPrompt(
        List<ChatMessage> conversation)
    {
        var prompt = new StringBuilder();

        prompt.AppendLine("System:");
        prompt.AppendLine(SystemPrompt);
        prompt.AppendLine();

        foreach (ChatMessage message in conversation)
        {
            switch (message.Role)
            {
                case "user":
                    prompt.AppendLine("User:");
                    prompt.AppendLine(message.Content);
                    prompt.AppendLine();
                    break;

                case "assistant":
                    prompt.AppendLine("Assistant:");
                    prompt.AppendLine(message.Content);
                    prompt.AppendLine();
                    break;
            }
        }

        prompt.AppendLine("Assistant:");

        return prompt.ToString();
    }
}
