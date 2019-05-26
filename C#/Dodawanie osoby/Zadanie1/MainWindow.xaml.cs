using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;

namespace Zadanie1
{
    /// <summary>
    /// Logika interakcji dla klasy MainWindow.xaml
    /// </summary>
    /// 

    public class Czlowiek
    {
        public string imie { get; set; }
        public string nazwisko { get; set; }
        public string plec { get; set; }
        public override string ToString()
        {
            return this.imie + ' ' + this.nazwisko + ", " + this.plec;
        }

    }
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private void photoChoose(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "JPG (*.jpg)|*.jpg|PNG (*.png)|*.png|All files (*.*)|*.*";
            if (openFileDialog.ShowDialog() == true)
            {
                Uri fileUri = new Uri(openFileDialog.FileName);
                imgDynamic.Source = new BitmapImage(fileUri);
            }
        }
        private void aMan(object sender, RoutedEventArgs e)
        {
            Woman.IsChecked = false;
            Ufolud.IsChecked = false;
        }

        private void aWoman(object sender, RoutedEventArgs e)
        {
            Man.IsChecked = false;
            Ufolud.IsChecked = false;
        }

        private void aUfolud(object sender, RoutedEventArgs e)
        {
            Man.IsChecked = false;
            Woman.IsChecked = false;
        }
        List<Czlowiek> ludzie = new List<Czlowiek>();
        private void add(object sender, RoutedEventArgs e)
        {
            string aPlec;
            bool flag = true;
            if (aImie.Text.Length == 0)
            {
                flag = false;
                MessageBox.Show("Brak podanego imienia");
            }

            if (aNazwisko.Text.Length == 0)
            {
                flag = false;
                MessageBox.Show("Brak podanego nazwiska");
            }
            if (Man.IsChecked == false && Woman.IsChecked == false && Ufolud.IsChecked == false)
            {
                flag = false;
                MessageBox.Show("Brak wybranej płci");
            }
            if (flag == true)
            {
                if (Man.IsChecked == true) aPlec = "Mężczyzna";
                else if (Woman.IsChecked == true) aPlec = "Kobieta";
                else aPlec = "Ufolud";
                listView.Items.Add(new Czlowiek() { imie = aImie.Text, nazwisko = aNazwisko.Text, plec = aPlec });
                MessageBox.Show("Dodano osobę!");
            }
        }
        private void del(object sender, RoutedEventArgs e)
        {
            listView.Items.Remove(listView.SelectedItems[0]);
        }

        private void delAll(object sender, RoutedEventArgs e)
        {
            listView.Items.Clear();
        }

    }
}
