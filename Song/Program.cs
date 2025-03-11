using System;
using System.Collections.Generic;
using System.IO;

namespace Song_Class
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //To test the constructor and the ToString method
            Console.WriteLine(new Song("Baby", "Justin Bieber", 3.35, SongGenre.Pop));
            //This is first time that you are using the bitwise or. It is used to specify a combination of genres
            Console.WriteLine(new Song("The Promise", "Chris Cornell", 4.26, SongGenre.Country | SongGenre.Rock));
            Library.LoadSongs("Week_03_lab_09_songs4.txt"); //Class methods are invoke with the class name
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

        public enum SongGenre
        {
            Unclassified = 0,
            Pop = 0b000001,
            Rock = 0b000010,
            Blues = 0b000100,
            Country = 0b001000,
            Metal = 0b010000,
            Soul = 0b100000,
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
                return $"{Title} by {Artist} ({Genre}) {Length}min";
            }
        }

        public static class Library
        {
            private static List<Song> songs = new List<Song>();

            public static void DisplaySongs()
            {
                foreach (Song song in songs)
                {
                    Console.WriteLine(song);
                }
            }

            public static void DisplaySongs(double longerThan)
            {
                foreach (Song song in songs)
                {
                    if (song.Length > longerThan)
                    {
                        Console.WriteLine(song);
                    }
                }
            }

            public static void DisplaySongs(SongGenre genre)
            {
                foreach (Song song in songs)
                {
                    if ((song.Genre & genre) == genre)  // Fixed bitwise OR check
                    {
                        Console.WriteLine(song);
                    }
                }
            }

            public static void DisplaySongs(string artist)
            {
                foreach (Song song in songs)
                {
                    if (song.Artist == artist)
                    {
                        Console.WriteLine(song);
                    }
                }
            }

            public static void LoadSongs(string fileName)
            {
                using (TextReader reader = new StreamReader(fileName))
                {
                    string title;
                    while ((title = reader.ReadLine()) != null)
                    {
                        string artist = reader.ReadLine();
                        double length = Convert.ToDouble(reader.ReadLine());
                        SongGenre genre = (SongGenre)Enum.Parse(typeof(SongGenre), reader.ReadLine());
                        Song newSong = new Song(title, artist, length, genre);
                        songs.Add(newSong);
                    }
                }
            }
        }
    }
}
 