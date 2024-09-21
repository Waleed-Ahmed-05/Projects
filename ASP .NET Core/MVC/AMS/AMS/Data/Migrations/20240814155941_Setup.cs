using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace AMS.Data.Migrations
{
    /// <inheritdoc />
    public partial class Setup : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "Add_Flight",
                columns: table => new
                {
                    Flight_ID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Departing_From = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Arrival_At = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Departing_Date_01 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Arrival_Date_01 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Departing_Time_01 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Arrival_Time_01 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Departing_Date_02 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Arrival_Date_02 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Departing_Time_02 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Arrival_Time_02 = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Ticket_Price = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Class = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Status = table.Column<string>(type: "nvarchar(max)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Add_Flight", x => x.Flight_ID);
                });

            migrationBuilder.CreateTable(
                name: "Book_Flight",
                columns: table => new
                {
                    Booking_ID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Flight_ID = table.Column<int>(type: "int", nullable: false),
                    First_Name = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Last_Name = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Nationality = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    CNIC = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    IBAN = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    CVV = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Date = table.Column<string>(type: "nvarchar(max)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Book_Flight", x => x.Booking_ID);
                });

            migrationBuilder.CreateTable(
                name: "Contact_us",
                columns: table => new
                {
                    Contact_ID = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    First_Name = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Last_Name = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Phone = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Email_ID = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Subject = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Message = table.Column<string>(type: "nvarchar(max)", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_Contact_us", x => x.Contact_ID);
                });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "Add_Flight");

            migrationBuilder.DropTable(
                name: "Book_Flight");

            migrationBuilder.DropTable(
                name: "Contact_us");
        }
    }
}
