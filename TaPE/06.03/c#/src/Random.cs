struct Random
{
    private uint _val;

    public Random(uint seed)
    {
        _val = seed;
    }

    public uint Next() => _val = (1103515245 * _val + 12345) % 2147483648;
    public uint Next(uint start, uint end) => Next() % (end - start + 1) + start;
}
