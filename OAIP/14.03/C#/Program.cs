using System;
using System.Linq;
using System.Net.Http;

var client = new WeatherClient();

var datas = await client.GetData();

Console.WriteLine("|{0,-20}|{1,-5}|{2,-9}|{3,-8}|", "UTC Date", "Radio", "Planetary", "Largest");
Console.WriteLine("|{0,-20}|{1,-5}|{2,-9}|{3,-8}|", "", "flux", "A Index", "Kp Index");
Console.WriteLine("\nAll Data:\n");

foreach (var data in datas)
{
    Console.WriteLine(data);
}
var date = DateTime.Now;
Console.WriteLine($"\nData by {date}:\n");
Console.WriteLine(await client.GetWeather(date));

var dateStart = DateTime.Now;
var dateEnd = dateStart.AddDays(4);
Console.WriteLine($"\nData between {dateStart} and {dateEnd}:\n");
datas = await client.GetWeather(dateStart, dateEnd);
foreach (var data in datas)
{
    Console.WriteLine(data);
}

class WeatherClient
{
    public async Task<IEnumerable<WeatherData>> GetData()
    {
        using var client = new HttpClient();

        var response = await client
            .GetStringAsync("https://services.swpc.noaa.gov/text/27-day-outlook.txt");

        var datas = response.Split('\n', StringSplitOptions.RemoveEmptyEntries)
            .Where(line => !line.StartsWith('#'))
            .Where(line => !line.StartsWith(':'))
            .Select(line => WeatherData.Parse(line));

        return datas;
    }
    public async Task<WeatherData?> GetWeather(DateTime date)
    {
        return (await GetData()).FirstOrDefault(w => w.UTCDate.Date == date.Date);
    }
    public async Task<IEnumerable<WeatherData>> GetWeather(DateTime start, DateTime end)
    {
        return (await GetData())
            .Where(w => w.UTCDate.Date >= start.Date && w.UTCDate.Date <= end);
    }
}

struct WeatherData
{
    public DateTime UTCDate { get; set; }
    public uint RadioFlux { get; set; }
    public uint PlanetaryAIndex { get; set; }
    public uint LargestKpIndex { get; set; }

    public static WeatherData Parse(string text)
    {
        var values = text
            .Replace("  ", "\t")
            .Split('\t', StringSplitOptions.RemoveEmptyEntries)
            .Select(s => s.Trim()).ToArray();
        return new()
        {
            UTCDate = DateTime.Parse(values[0]),
            RadioFlux = uint.Parse(values[1]),
            PlanetaryAIndex = uint.Parse(values[2]),
            LargestKpIndex = uint.Parse(values[3]),
        };
    }

    public override string ToString()
    {
        return String.Format(
            "|{0,-20}|{1,-5}|{2,-9}|{3,-8}|",
            UTCDate,
            RadioFlux,
            PlanetaryAIndex,
            LargestKpIndex);
        return $"{UTCDate};\t{RadioFlux};\t{PlanetaryAIndex};\t{LargestKpIndex}";
    }
}
