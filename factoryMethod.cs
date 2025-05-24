using System;
namespace Factory
{
    public interface IFormat
    {
        void Print();
    }
    public abstract class Archiver
    {
        public abstract IFormat CreateArchive();
        public void NewArchive()
        {
            IFormat archive = CreateArchive();
            archive.Print();
        }
    } 
    public class Format7z : IFormat
    {
        public void Print() {
            Console.WriteLine(".7z format archive");
        }
    }
    public class FormatRar : IFormat
    {
        public void Print()
        {
            Console.WriteLine(".rar format archive");
        }
    }
    public class Archiver7z : Archiver
    {
        public override IFormat CreateArchive()
        {
            return new Format7z();
        }
    }
    public class ArchiverRar : Archiver
    {
        public override IFormat CreateArchive()
        {
            return new FormatRar();
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            Archiver sevenZip = new Archiver7z();
            sevenZip.NewArchive();
            Archiver winRar = new ArchiverRar();
            winRar.NewArchive();
        }
    }
}
