using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace AMS.Data.Migrations
{
    /// <inheritdoc />
    public partial class gh : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AddColumn<string>(
                name: "Baby",
                table: "Book_Flight",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<string>(
                name: "Baggage",
                table: "Book_Flight",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<string>(
                name: "Music",
                table: "Book_Flight",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");

            migrationBuilder.AddColumn<string>(
                name: "Sport",
                table: "Book_Flight",
                type: "nvarchar(max)",
                nullable: false,
                defaultValue: "");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropColumn(
                name: "Baby",
                table: "Book_Flight");

            migrationBuilder.DropColumn(
                name: "Baggage",
                table: "Book_Flight");

            migrationBuilder.DropColumn(
                name: "Music",
                table: "Book_Flight");

            migrationBuilder.DropColumn(
                name: "Sport",
                table: "Book_Flight");
        }
    }
}
