using System.Text;

struct Card
{
    public const uint BingoSize = 5;
    public Card()
    {
        Cells = new Cell[5, 5];
        Random r = new Random();
        for (uint i = 0; i < BingoSize; i++)
        {
            for (uint j = 0; j < BingoSize; j++)
            {
                var start = 1 + i * 15;
                var end = start + 15;
                Cells[i, j] = new(r.Next(start, end));
            }
        }
    }
    public Cell[,] Cells;
    public void CheckCell(uint number)
    {
        for (int i = 0; i < BingoSize; i++)
        {
            for (int j = 0; j < BingoSize; j++)
            {
                if (Cells[i, j].Number == number)
                {
                    Cells[i, j].IsChecked = true;
                }
            }
        }
    }
    public static char[] Bingo = { 'B', 'I', 'N', 'G', 'O' };
    public override string ToString()
    {
        StringBuilder sb = new();

        for (int i = 0; i < BingoSize; i++)
        {
            sb.Append($"{Bingo[i]} ");
            for (int j = 0; j < BingoSize; j++)
            {
                sb.Append($"{Cells[i, j]} ");
            }
            sb.Append("\n");
        }
        return sb.ToString();
    }
    public bool IsWinner()
    {
        for (int i = 0; i < BingoSize; i++)
        {
            for (int j = 0; j < BingoSize; j++)
            {
                if (!Cells[i, j].IsChecked)
                {
                    return false;
                }
            }
        }
        return true;
    }
}
struct Cell
{
    public Cell(uint number) =>
        Number = number;

    public uint Number;
    public bool IsChecked = false;

    public override string ToString()
    {
        if (IsChecked)
        {
            return $"[{Number}]";
        }

        return $" {Number} ";
    }
}
