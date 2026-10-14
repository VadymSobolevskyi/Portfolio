using System;
using System.Text;
using System.Threading.Tasks;

namespace OllamaPhi3App
{
    class Program
    {
        static async Task Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            
            var ollamaService = new OllamaService();

            PrintHeader();

            while (true)
            {
                string? prompt = GetUserPrompt();

                if (IsExitCommand(prompt))
                {
                    break;
                }

                await ProcessPromptAsync(ollamaService, prompt!);
                PrintSeparator();
            }
        }

        private static void PrintHeader()
        {
            Console.WriteLine("=== Консольний генератор тексту (Ollama + Phi-3) ===");
            Console.WriteLine("Введіть ваш промпт (або 'exit' для виходу):\n");
        }

        private static string? GetUserPrompt()
        {
            Console.Write("Промпт: ");
            return Console.ReadLine();
        }

        private static bool IsExitCommand(string? prompt)
        {
            return string.IsNullOrWhiteSpace(prompt) || prompt.Equals("exit", StringComparison.OrdinalIgnoreCase);
        }

        private static async Task ProcessPromptAsync(OllamaService service, string prompt)
        {
            Console.WriteLine("\nГенеруємо відповідь...\n");

            try
            {
                string? result = await service.GenerateTextAsync(prompt);
                
                if (!string.IsNullOrEmpty(result))
                {
                    Console.WriteLine($"Відповідь:\n{result}");
                }
                else
                {
                    Console.WriteLine("Отримано порожню відповідь від моделі.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[Помилка]: {ex.Message}");
            }
        }

        private static void PrintSeparator()
        {
            Console.WriteLine("\n" + new string('-', 50) + "\n");
        }
    }
}