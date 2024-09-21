using Microsoft.AspNetCore.Identity.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore;
using AMS.Models;

namespace AMS.Data
{
    public class ApplicationDbContext : IdentityDbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }
        public DbSet<AMS.Models.Add_Flight> Add_Flight { get; set; } = default!;
        public DbSet<AMS.Models.Book_Flight> Book_Flight { get; set; } = default!;
        public DbSet<AMS.Models.Contact_us> Contact_us { get; set; } = default!;
        public DbSet<AMS.Models.Add_Car> Add_Car { get; set; } = default!;
        public DbSet<AMS.Models.Book_Car> Book_Car { get; set; } = default!;
        public DbSet<AMS.Models.Users> Users { get; set; } = default!;
    }
}
