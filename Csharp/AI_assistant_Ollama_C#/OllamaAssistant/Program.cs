using OllamaAssistant.Models;
using OllamaAssistant.Services;

Console.OutputEncoding = System.Text.Encoding.UTF8;

var ollamaService = new OllamaService();

var conversation = new List<ChatMessage>();

Console.WriteLine("==========================================");
Console.WriteLine("          OLLAMA AI ASSISTANT");
Console.WriteLine("==========================================");
Console.WriteLine();
Console.WriteLine("Модель: phi3");
Console.WriteLine();
Console.WriteLine("Команди:");
Console.WriteLine("  exit   - завершити програму");
Console.WriteLine("  clear  - очистити історію діалогу");
Console.WriteLine("  history - показати історію");
Console.WriteLine();
Console.WriteLine("==========================================");
Console.WriteLine();

while (true)
{
    Console.Write("You: ");

    string? userInput = Console.ReadLine();

    if (string.IsNullOrWhiteSpace(userInput))
    {
        continue;
    }

    userInput = userInput.Trim();

    // Завершення програми
    if (userInput.Equals(
            "exit",
            StringComparison.OrdinalIgnoreCase))
    {
        Console.WriteLine();
        Console.WriteLine("До побачення!");

        break;
    }

    // Очищення історії
    if (userInput.Equals(
            "clear",
            StringComparison.OrdinalIgnoreCase))
    {
        conversation.Clear();

        Console.WriteLine();
        Console.WriteLine("Історію діалогу очищено.");
        Console.WriteLine();

        continue;
    }

    // Показати історію
    if (userInput.Equals(
            "history",
            StringComparison.OrdinalIgnoreCase))
    {
        ShowHistory(conversation);

        continue;
    }

    // Додаємо повідомлення користувача
    conversation.Add(new ChatMessage
    {
        Role = "user",
        Content = userInput
    });

    try
    {
        Console.WriteLine();
        Console.Write("AI: ");

        string answer =
            await ollamaService.GenerateResponseAsync(
                conversation);

        Console.WriteLine(answer);

        // Додаємо відповідь AI в історію
        conversation.Add(new ChatMessage
        {
            Role = "assistant",
            Content = answer
        });

        Console.WriteLine();
    }
    catch (HttpRequestException)
    {
        Console.WriteLine();
        Console.WriteLine(
            "Помилка підключення до Ollama.");

        Console.WriteLine();
        Console.WriteLine(
            "Переконайтеся, що Ollama запущена.");

        Console.WriteLine(
            "Спробуйте виконати:");

        Console.WriteLine();
        Console.WriteLine("    ollama run phi3");

        Console.WriteLine();

        // Видаляємо останнє повідомлення,
        // оскільки AI не зміг на нього відповісти.
        conversation.RemoveAt(
            conversation.Count - 1);
    }
    catch (TaskCanceledException)
    {
        Console.WriteLine();
        Console.WriteLine(
            "Запит до Ollama перевищив час очікування.");

        Console.WriteLine();

        conversation.RemoveAt(
            conversation.Count - 1);
    }
    catch (Exception ex)
    {
        Console.WriteLine();
        Console.WriteLine(
            $"Помилка: {ex.Message}");

        Console.WriteLine();

        conversation.RemoveAt(
            conversation.Count - 1);
    }
}

static void ShowHistory(
    List<ChatMessage> conversation)
{
    Console.WriteLine();
    Console.WriteLine("========== HISTORY ==========");

    if (conversation.Count == 0)
    {
        Console.WriteLine("Історія порожня.");
    }
    else
    {
        foreach (ChatMessage message in conversation)
        {
            string role =
                message.Role == "user"
                    ? "You"
                    : "AI";

            Console.WriteLine();
            Console.WriteLine($"{role}:");
            Console.WriteLine(message.Content);
        }
    }

    Console.WriteLine();
    Console.WriteLine("=============================");
    Console.WriteLine();
}