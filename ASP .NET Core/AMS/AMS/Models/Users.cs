using System.ComponentModel.DataAnnotations;

namespace AMS.Models
{
    public class Users
    {
        [Key]
        public int User_ID { get; set; }
        [Required]
        public string First_Name { get; set; }
        public string Last_Name { get; set; }
        public string Email { get; set; }
        public string Password { get; set; }
        public string Contact { get; set; }
        public string Gender { get; set; }
        public string Date {  get; set; }
        public string Role { get; set; }
    }
}
