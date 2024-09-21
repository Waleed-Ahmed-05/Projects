using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using AMS.Data;
using AMS.Models;

namespace AMS.Controllers
{
    public class Book_FlightController : Controller
    {
        private readonly ApplicationDbContext _context;

        public Book_FlightController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Book_Flight
        public async Task<IActionResult> Index(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View(await _context.Book_Flight.ToListAsync());
        }

        // GET: Book_Flight/Details/5
        public async Task<IActionResult> Details(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            var Flight = _context.Add_Flight.ToList();
            ViewBag.Flight = Flight;
            if (id == null)
            {
                return NotFound();
            }

            var book_Flight = await _context.Book_Flight
                .FirstOrDefaultAsync(m => m.Booking_ID == id);
            if (book_Flight == null)
            {
                return NotFound();
            }

            return View(book_Flight);
        }

        // GET: Book_Flight/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: Book_Flight/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Booking_ID,Flight_ID,User_ID,Ticket_Price,First_Name,Last_Name,Nationality,CNIC,IBAN,CVV,Date,Baggage,Baby,Music,Sport,Pre_Food,WheelChair,Booking_Class,Adult_Seats,Child_Seats")] Book_Flight book_Flight)
        {
            if (ModelState.IsValid)
            {
                _context.Add(book_Flight);
                await _context.SaveChangesAsync();
                TempData["SuccessMessage"] = "Flight booked successfully";
                return RedirectToAction(nameof(Index), new { User_ID = book_Flight.User_ID });
            }
            return View(book_Flight);
        }

        // GET: Book_Flight/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var book_Flight = await _context.Book_Flight.FindAsync(id);
            if (book_Flight == null)
            {
                return NotFound();
            }
            return View(book_Flight);
        }

        // POST: Book_Flight/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Booking_ID,Flight_ID,User_ID,Ticket_Price,First_Name,Last_Name,Nationality,CNIC,IBAN,CVV,Date,Baggage,Baby,Music,Sport,Pre_Food,WheelChair,Booking_Class,Adult_Seats,Child_Seats")] Book_Flight book_Flight)
        {
            TempData["SuccessMessage"] = "Changes Saved Successfully";
            if (id != book_Flight.Booking_ID)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(book_Flight);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!Book_FlightExists(book_Flight.Booking_ID))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index), new { User_ID = book_Flight.User_ID});
            }
            return View(book_Flight);
        }

        // GET: Book_Flight/Delete/5
        public async Task<IActionResult> Delete(int? id, int User_ID)
        {
            TempData["SuccessMessage"] = "Flight Reservation Removed";
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var book_Flight = await _context.Book_Flight
                .FirstOrDefaultAsync(m => m.Booking_ID == id);
            if (book_Flight == null)
            {
                return NotFound();
            }

            return View(book_Flight);
        }

        // POST: Book_Flight/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id, int User_ID)
        {
            var book_Flight = await _context.Book_Flight.FindAsync(id);
            if (book_Flight != null)
            {
                _context.Book_Flight.Remove(book_Flight);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new { User_ID = book_Flight.User_ID });
        }

        private bool Book_FlightExists(int id)
        {
            return _context.Book_Flight.Any(e => e.Booking_ID == id);
        }
        public IActionResult CreateNFA()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Get_Flight_ID(int ID, float Cost, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Flight_ID = ID;
            ViewBag.Cost = Cost;
            return View("CreateNFA");
        }

        [HttpPost]
        public async Task<IActionResult> LuggageAndEquipment(int ID, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Data_Flight = await _context.Book_Flight.FindAsync(ID);
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> SpecialNeeds(int ID, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Data_Flight = await _context.Book_Flight.FindAsync(ID);
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> ManageBooking(int ID, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Data_Flight = await _context.Book_Flight.FindAsync(ID);
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> ManageUpgrades(int ID, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Data_Flight = await _context.Book_Flight.FindAsync(ID);
            return View();
        }
        public async Task<IActionResult> Payment(int Flight_ID,int User_ID, float Ticket_Price, string First_Name, string Last_Name, string Nationality, string CNIC, string Adult_Seats, string Child_Seats)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Flight_ID = Flight_ID;
            ViewBag.Ticket_Price = Ticket_Price;
            ViewBag.First_Name = First_Name;
            ViewBag.Last_Name = Last_Name;
            ViewBag.Nationality = Nationality;
            ViewBag.CNIC = CNIC;
            ViewBag.Adult_Seats = Adult_Seats;
            ViewBag.Child_Seats = Child_Seats;
            return View("Payment");
        }
        public async Task<IActionResult> Flights(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View(await _context.Add_Flight.ToListAsync());
        }
        public async Task<IActionResult> Bookings_01(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            var Flight = _context.Add_Flight.ToList();
            ViewBag.Flight = Flight;
            return View(await _context.Book_Flight.ToListAsync());
        }
        public async Task<IActionResult> Bookings_02(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            var Flight = _context.Add_Flight.ToList();
            ViewBag.Flight = Flight;
            return View(await _context.Book_Flight.ToListAsync());
        }
        public async Task<IActionResult> Bookings_03(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            var Flight = _context.Add_Flight.ToList();
            ViewBag.Flight = Flight;
            return View(await _context.Book_Flight.ToListAsync());
        }
        public async Task<IActionResult> Bookings_04(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            var Flight = _context.Add_Flight.ToList();
            ViewBag.Flight = Flight;
            return View(await _context.Book_Flight.ToListAsync());
        }
    }
}
