using System;
using System.Linq;
using System.Threading;
using System.Collections.Generic;
struct Game
{
    private string[] _args = Array.Empty<string>();
    public Game(string[] args)
    {
        _args = args;
    }
    public int Start()
    {
        var card = new Card();
        Random r = new Random();
        Console.WriteLine(card);

        while (!card.IsWinner())
        {
            Console.Clear();
            card.CheckCell(r.Next(0, 80));
            Console.WriteLine(card);
            Thread.Sleep(500);
        }
        return 0;
    }
}
