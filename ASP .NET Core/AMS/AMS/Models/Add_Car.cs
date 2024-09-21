using System.ComponentModel.DataAnnotations;

namespace AMS.Models
{
    public class Add_Car
    {
        [Key]
        public int Car_ID { get; set; }
        [Required]
        public int User_ID { get; set; }
        public string Car_Name { get; set; }
        public string First_Name { get; set; }
        public string Last_Name { get; set; }
        public string Driver_Age { get; set; }
        public string Rating { get; set; }
        public string Number_Plate { get; set; }
        public string Contact {  get; set; }
    }
}
