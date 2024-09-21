using System.ComponentModel.DataAnnotations;

namespace AMS.Models
{
    public class Contact_us
    {
        [Key]
        public int Contact_ID { get; set; }
        [Required]
        public int User_ID { get; set; }
        public string First_Name { get; set; }
        public string Last_Name { get; set; }
        public string Phone { get; set; }
        public string Email_ID { get; set; }
        public string Subject { get; set; }
        public string Message { get; set; }
    }
}
