using System.ComponentModel.DataAnnotations;

namespace AMS.Models
{
    public class Book_Flight
    {
        [Key]
        public int Booking_ID { get; set; }
        [Required]
        public int Flight_ID { get; set; }
        public int User_ID { get; set; }
        public float Ticket_Price { get; set; }
        public string First_Name { get; set; }
        public string Last_Name { get; set; }
        public string Nationality { get; set; }
        public string CNIC { get; set; }
        public string IBAN { get; set; }
        public string CVV { get; set; }
        public string Date { get; set; }
        public string Baggage { get; set; }
        public string Baby {  get; set; }
        public string Music { get; set; }
        public string Sport { get; set; }
        public string Pre_Food { get; set; }
        public string WheelChair { get; set; }
        public string Booking_Class { get; set; }
        public int Adult_Seats { get; set; }
        public int Child_Seats { get; set; }
    }
}
