using System.ComponentModel.DataAnnotations;

namespace AMS.Models
{
    public class Book_Car
    {
        [Key]
        public int Booking_Car_ID { get; set; }
        [Required]
        public string Car_ID { get; set; }
        public int User_ID { get; set; }
        public string First_Name { get; set; }
        public string Last_Name { get; set; }
        public string Pickup_Location {  get; set; }
        public string Pickup_Time { get; set; }
        public string Dropoff { get; set; }
        public string Contact { get; set; }
        public string  IBAN { get; set; }
        public int CVV { get; set; }
        public string Date {  get; set; }
    }
}
