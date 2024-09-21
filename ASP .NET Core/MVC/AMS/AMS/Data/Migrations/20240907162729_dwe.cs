using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace AMS.Data.Migrations
{
    /// <inheritdoc />
    public partial class dwe : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Adult_Seats",
                table: "Book_Car");

            migrationBuilder.DropColumn(
                name: "Child_Seats",
                table: "Book_Car");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<string>(
                name: "Adult_Seats",
                table: "Book_Car",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<string>(
                name: "Child_Seats",
                table: "Book_Car",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");
        }
    }
}
