public class Song
{
    public string Title { get; }
    public string Artist { get; }
    public double Length { get; }
    public SongGenre Genre { get; }

    public Song(string title, string artist, double length, SongGenre genre)
    {
        Title = title;
        Artist = artist;
        Length = length;
        Genre = genre;
    }

    public override string ToString()
    {
        return $"{Title} by {Artist} ({Genre}) {Length}min";
    }
}

public static class Library
{
    private static List<Song> songs = new List<Song>();

    public static void LoadSongs(string fileName)
    {
        if (!File.Exists(fileName))
        {
            Console.WriteLine("File not found!");
            return;
        }

        using (StreamReader reader = new StreamReader(fileName))
        {
            while (!reader.EndOfStream)
            {
                string title = reader.ReadLine();
                if (string.IsNullOrWhiteSpace(title)) break;
                
                string artist = reader.ReadLine();
                double length = Convert.ToDouble(reader.ReadLine());
                SongGenre genre = Enum.Parse<SongGenre>(reader.ReadLine());
                
                songs.Add(new Song(title, artist, length, genre));
            }
        }
    }

    public static void DisplaySongs()
    {
        foreach (var song in songs)
            Console.WriteLine(song);
    }

    public static void DisplaySongs(double longerThan)
    {
        foreach (var song in songs)
            if (song.Length > longerThan)
                Console.WriteLine(song);
    }

    public static void DisplaySongs(SongGenre genre)
    {
        foreach (var song in songs)
            if (song.Genre.HasFlag(genre))
                Console.WriteLine(song);
    }

    public static void DisplaySongs(string artist)
    {
        foreach (var song in songs)
            if (song.Artist.Equals(artist, StringComparison.OrdinalIgnoreCase))
                Console.WriteLine(song);
    }
}
