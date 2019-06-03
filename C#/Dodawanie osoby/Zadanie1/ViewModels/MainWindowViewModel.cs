using Microsoft.Win32;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Windows.Input;
using System.Windows.Media.Imaging;
using Zadanie1.Models;

namespace Zadanie1.ViewModels
{
    class MainWindowViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        private string _name;
        public string Name
        {
            get
            {
                return _name;
            }
            set
            {
                _name = value;
                OnPropertyRaised("Name");
            }
        }

        private string _surname;
        public string Surname
        {
            get
            {
                return _surname;
            }
            set
            {
                _surname = value;
                OnPropertyRaised("Surname");
            }
        }


        private List<string> _items = new List<string>();
        public List<string> Items
        {
            get
            {
                return _items;
            }
            set
            {
                _items = value;
                OnPropertyRaised("Items");
            }
        }
        private string _sitems;
        public string SItems
        {
            get
            {
                return _sitems;
            }
            set
            {
                _sitems = value;
                OnPropertyRaised("SItems");
            }
        }

        public ICommand SelectImage { get; set; }
        private BitmapImage _image;
        public BitmapImage Image
        {
            get
            {
                return _image;
            }
            set
            {
                _image = value;
                OnPropertyRaised("Image");
            }
        }

        private void SelectImage_Execute (object obj)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "JPG (*.jpg)|*.jpg|PNG (*.png)|*.png|All files (*.*)|*.*";
            if (openFileDialog.ShowDialog() == true)
            {
                Uri fileUri = new Uri(openFileDialog.FileName);
                Image = new BitmapImage(fileUri);
            }
        }

        private ObservableCollection<Person> _people;
        public ObservableCollection<Person> People
        {
            get { return _people; }
            set { _people = value; }
        }
        public ICommand AddButtonCommand { get; set; }
        private bool AddButton_CanExecute(object obj)
        {
            if (Name != null && Surname != null && SItems != null && Image != null) return true;
            else return false;
        }
        private void AddButtonCommand_Execute (object obj)
        {
            People.Add(new Person() { FirstName = Name, LastName = Surname, Image = Image, WorkName = SItems });
            Name = null;
            Surname = null;
            Image = null;
            SItems = null;
        }

        private Person _selection;
        public Person Selection
        {
            get
            {
                return _selection;
            }
            set
            {
                _selection = value;
                OnPropertyRaised("Selection");
            }
        }

        public ICommand RemoveCheckedButtonCommand { get; set; }
        private bool RemoveCheckedButton_CanExecute(object obj)
        {
            if (Selection != null) return true;
            else return false;
        }
        private void RemoveCheckedButtonCommand_Execute (object obj)
        {
            People.Remove(Selection);
        }

        public ICommand RemoveAllButtonCommand { get; set; }
        private bool RemoveAllButton_CanExecute(object obj)
        {
            return People.Count > 0;
        }
        private void RemoveAllButtonCommand_Execute (object obj)
        {
            People.Clear();
        }
        public MainWindowViewModel()
        {
            Items = new List<string>() { "Cieć", "Programista", "Bezrobotny" };
            People = new ObservableCollection<Person>();
            SelectImage = new RelayCommand(SelectImage_Execute);
            AddButtonCommand = new RelayCommand(AddButtonCommand_Execute, AddButton_CanExecute);
            RemoveCheckedButtonCommand = new RelayCommand(RemoveCheckedButtonCommand_Execute, RemoveCheckedButton_CanExecute);
            RemoveAllButtonCommand = new RelayCommand(RemoveAllButtonCommand_Execute, RemoveAllButton_CanExecute);
        }

        private void OnPropertyRaised(string propertyname)
        {
            if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs(propertyname));
        }
        
    }
}
