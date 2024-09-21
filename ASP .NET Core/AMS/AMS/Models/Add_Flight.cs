using System.ComponentModel.DataAnnotations;

namespace AMS.Models
{
    public class Add_Flight
    {

        [Key]
        public int Flight_ID { get; set; }
        [Required]
        public string User_ID { get; set; }
        public string Departing_From { get; set; }
        public string Arrival_At { get; set; }
        public string Departing_Date_01 { get; set; }
        public string Arrival_Date_01 { get; set; }
        public string Departing_Time_01 { get; set; }
        public string Arrival_Time_01 { get; set; }
        public string Departing_Date_02 { get; set; }
        public string Arrival_Date_02 { get; set; }
        public string Departing_Time_02 { get; set; }
        public string Arrival_Time_02 { get; set; }
        public string Ticket_Price { get; set; }
        public string Class { get; set; }
        public string Status { get; set; }
    }
}
