using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;

namespace Zadanie1.Models
{
    class Person : INotifyPropertyChanged
    {
        private string _firstName;
        public string FirstName
        {
            get
            {
                return _firstName;
            }
            set
            {
                _firstName = value;
                OnPropertyRaised("FirstName");
            }
        }
        private string _lastName;
        public string LastName
        {
            get
            {
                return _lastName;
            }
            set
            {
                _lastName = value;
                OnPropertyRaised("LastName");
            }
        }
        private string _workName;
        public string WorkName
        {
            get
            {
                return _workName;
            }
            set
            {
                _workName = value;
                OnPropertyRaised("WorkName");
            }
        }
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
        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyRaised (string propertyname)
        {
            if (PropertyChanged != null) PropertyChanged(this, new PropertyChangedEventArgs(propertyname));
        }
    }
}
