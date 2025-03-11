using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Lab_Assignment_Week_3_Songs
{
    [Flags]
    public enum SongGenre
    {
        Unclassified = 0,
        Pop = 0b1,
        Rock = 0b10,
        Blues = 0b100,
        Country = 0b1000,  // Fixed duplicate bitwise value
        Metal = 0b10_000,
        Soul = 0b100_000
    }

    public class Song
    {
        public string Artist { get; }
        public string Title { get; }
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
            return $"{Title} by {Artist} ({GetGenreString(Genre)}) {Length}min";
        }

        private string GetGenreString(SongGenre genre)
        {
            var genres = Enum.GetValues(typeof(SongGenre))
                             .Cast<SongGenre>()
                             .Where(g => (genre & g) == g && g != SongGenre.Unclassified);
            return string.Join(", ", genres);
        }
    }

    public static class Library
    {
        private static List<Song> songs = new List<Song>();

        public static void LoadSongs(string filename)
        {
            songs.Clear();
            try
            {
                using (StreamReader reader = new StreamReader(filename))
                {
                    while (!reader.EndOfStream)
                    {
                        string title = reader.ReadLine();
                        if (string.IsNullOrEmpty(title)) break;

                        string artist = reader.ReadLine();
                        if (!double.TryParse(reader.ReadLine(), out double length)) continue;

                        string genreString = reader.ReadLine();
                        SongGenre genre = SongGenre.Unclassified;

                        if (!string.IsNullOrEmpty(genreString))
                        {
                            var genres = genreString.Split(',').Select(g => g.Trim());
                            foreach (var g in genres)
                            {
                                if (Enum.TryParse(g, out SongGenre parsedGenre))
                                {
                                    genre |= parsedGenre;
                                }
                            }
                        }
                        songs.Add(new Song(title, artist, length, genre));
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error loading songs: {ex.Message}");
            }
        }

        public static void DisplaySongs()
        {
            foreach (var song in songs)
            {
                Console.WriteLine(song);
            }
        }

        public static void DisplaySongs(double longerThan)
        {
            foreach (var song in songs.Where(s => s.Length > longerThan))
            {
                Console.WriteLine(song);
            }
        }

        public static void DisplaySongs(SongGenre genre)
        {
            foreach (var song in songs.Where(s => (s.Genre & genre) == genre))
            {
                Console.WriteLine(song);
            }
        }

        public static void DisplaySongs(string artist)
        {
            foreach (var song in songs.Where(s => s.Artist.Equals(artist, StringComparison.OrdinalIgnoreCase)))
            {
                Console.WriteLine(song);
            }
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(new Song("Baby", "Justin Bieber", 3.35, SongGenre.Pop));
            Console.WriteLine(new Song("The Promise", "Chris Cornell", 4.26, SongGenre.Country | SongGenre.Rock));

            Library.LoadSongs("Week_03_lab_09_songs4.txt");
            Console.WriteLine("\n\nAll songs");
            Library.DisplaySongs();

            SongGenre genre = SongGenre.Rock;
            Console.WriteLine($"\n\n{genre} songs");
            Library.DisplaySongs(genre);

            string artist = "Bob Dylan";
            Console.WriteLine($"\n\nSongs by {artist}");
            Library.DisplaySongs(artist);

            double length = 5.0;
            Console.WriteLine($"\n\nSongs more than {length}mins");
            Library.DisplaySongs(length);
        }
    }
}
