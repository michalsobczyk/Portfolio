using InternetShop.Models;
using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Windows.Media.Imaging;
using Zadanie1.ViewModels;

namespace InternetShop.ViewModels
{
    class MainWindowViewModel : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;


        private ObservableCollection<Coffee> _coffeeCart;
        public ObservableCollection<Coffee> CoffeeCart
        {
            get
            {
                return _coffeeCart;
            }
            set
            {
                _coffeeCart = value;
                OnPropertyRaised("CoffeeCart");
            }
        }

        private ObservableCollection<Icecream> _icecreamCart;
        public ObservableCollection<Icecream> IcecreamCart
        {
            get
            {
                return _icecreamCart;
            }
            set
            {
                _icecreamCart = value;
                OnPropertyRaised("IcecreamCart");
            }
        }

        private ObservableCollection<Tea> _teaCart;
        public ObservableCollection<Tea> TeaCart
        {
            get
            {
                return _teaCart;
            }
            set
            {
                _teaCart = value;
                OnPropertyRaised("TeaCart");
            }
        }

        private ObservableCollection<Product> _cart;
        public ObservableCollection<Product> Cart
        {
            get
            {
                return _cart;
            }
            set
            {
                _cart = value;
                OnPropertyRaised("Cart");
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

        private ObservableCollection<Tea> _teas;
        public ObservableCollection<Tea> Teas
        {
            get
            {
                return _teas;
            }
            set
            {
                _teas = value;
                OnPropertyRaised("Teas");
            }
        }

        private ObservableCollection<Coffee> _coffees;
        public ObservableCollection<Coffee> Coffees
        {
            get { return _coffees; }
            set
            {
                _coffees = value;
                OnPropertyRaised("Coffees");
            }
        }

        private ObservableCollection<Icecream> _icecreams;
        public ObservableCollection<Icecream> Icecreams
        {
            get
            {
                return _icecreams;
            }
            set
            {
                _icecreams = value;
                OnPropertyRaised("Icecreams");
            }
        }

        private Product _selection;
        public Product Selection
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

        private void SelectImage_Execute(object obj)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "JPG (*.jpg)|*.jpg|PNG (*.png)|*.png|All files (*.*)|*.*";
            if (openFileDialog.ShowDialog() == true)
            {
                Uri fileUri = new Uri(openFileDialog.FileName);
                Image = new BitmapImage(fileUri);
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

        private double _prize;
        public double Prize
        {
            get
            {
                return _prize;
            }
            set
            {
                _prize = value;
                OnPropertyRaised("Prize");
            }
        }

        private string _description;
        public string Description
        {
            get
            {
                return _description;
            }
            set
            {
                _description = value;
                OnPropertyRaised("Description");
            }
        }

        private int _totalAmount;
        public int TotalAmount
        {
            get
            {
                return _totalAmount;
            }
            set
            {
                _totalAmount = value;
                OnPropertyRaised("TotalAmount");
            }
        }

        public ICommand AddButton { get; set; }
        public void AddButton_Execute(object obj)
        {
            if (SItems == "Coffee") Coffees.Add(new Coffee { Name = Name, Prize = Prize, Description = Description, Image = Image });
            if (SItems == "Tea") Teas.Add(new Tea { Name = Name, Prize = Prize, Description = Description, Image = Image });
            if (SItems == "Ice Cream") Icecreams.Add(new Icecream { Name = Name, Prize = Prize, Description = Description, Image = Image });
            Name = null;
            Prize = 0;
            Description = null;
            Image = null;
            SItems = null;
        }

        public bool AddButton_CanExecute(object obj)
        {
            if (Name != null && Prize != 0 && Description != null && Image != null && SItems != null) return true;
            else return false;
        }
        private double _cartValue;
        public double CartValue
        {
            get
            {
                return _cartValue;
            }
            set
            {
                _cartValue = value;
                OnPropertyRaised("CartValue");
            }
        }

        public ICommand AddToCart { get; set; }
        public void AddToCart_Execute (object obj)
        {
            Cart.Add(new Product { Name = Selection.Name, Prize = Selection.Prize, Description = Selection.Description, Image = Selection.Image, Amount = Selection.Amount });
            CartValue += (Selection.Prize * Selection.Amount);
            TotalAmount += Selection.Amount;
        }
        public bool AddToCart_CanExecute (object obj)
        {
            if (Selection != null && Selection.Prize > 0) return true;
            return false;
        }

        public MainWindowViewModel()
        {
            CartValue = 0;
            Items = new List<string>() { "Coffee", "Tea", "Ice Cream" };
            Coffees = new ObservableCollection<Coffee>();
            Teas = new ObservableCollection<Tea>();
            Icecreams = new ObservableCollection<Icecream>();
            CoffeeCart = new ObservableCollection<Coffee>();
            IcecreamCart = new ObservableCollection<Icecream>();
            TeaCart = new ObservableCollection<Tea>();
            Cart = new ObservableCollection<Product>();
            SelectImage = new RelayCommand(SelectImage_Execute);
            AddButton = new RelayCommand(AddButton_Execute, AddButton_CanExecute);
            AddToCart = new RelayCommand(AddToCart_Execute, AddToCart_CanExecute);
        }
        private void OnPropertyRaised(string propertyname)
        {
            if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs(propertyname));
        }
    }
}
