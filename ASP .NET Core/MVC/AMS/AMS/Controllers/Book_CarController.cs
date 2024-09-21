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
    public class Book_CarController : Controller
    {
        private readonly ApplicationDbContext _context;

        public Book_CarController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Book_Car
        public async Task<IActionResult> Index(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View(await _context.Book_Car.ToListAsync());
        }

        // GET: Book_Car/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var book_Car = await _context.Book_Car
                .FirstOrDefaultAsync(m => m.Booking_Car_ID == id);
            if (book_Car == null)
            {
                return NotFound();
            }

            return View(book_Car);
        }

        // GET: Book_Car/Create
        public IActionResult Create()
        {
            return View();
        }

        // POST: Book_Car/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Booking_Car_ID,Car_ID,User_ID,First_Name,Last_Name,Pickup_Location,Pickup_Time,Dropoff,Contact,IBAN,CVV,Date")] Book_Car book_Car)
        {
            if (ModelState.IsValid)
            {
                _context.Add(book_Car);
                await _context.SaveChangesAsync();
                TempData["SuccessMessage"] = "Car booked successfully";
                return RedirectToAction(nameof(Index), new { User_ID = book_Car.User_ID });
            }
            return View(book_Car);
        }

        // GET: Book_Car/Edit/5
        public async Task<IActionResult> Edit(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var book_Car = await _context.Book_Car.FindAsync(id);
            if (book_Car == null)
            {
                return NotFound();
            }
            return View(book_Car);
        }

        // POST: Book_Car/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Booking_Car_ID,Car_ID,User_ID,First_Name,Last_Name,Pickup_Location,Pickup_Time,Dropoff,Contact,IBAN,CVV,Date")] Book_Car book_Car)
        {
            if (id != book_Car.Booking_Car_ID)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(book_Car);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!Book_CarExists(book_Car.Booking_Car_ID))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                TempData["SuccessMessage"] = "Changes Saved Successfully";
                return RedirectToAction(nameof(Index), new { User_ID = book_Car.User_ID });
            }
            return View(book_Car);
        }

        // GET: Book_Car/Delete/5
        public async Task<IActionResult> Delete(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var book_Car = await _context.Book_Car
                .FirstOrDefaultAsync(m => m.Booking_Car_ID == id);
            if (book_Car == null)
            {
                return NotFound();
            }

            return View(book_Car);
        }

        // POST: Book_Car/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id, int User_ID)
        {
            var book_Car = await _context.Book_Car.FindAsync(id);
            if (book_Car != null)
            {
                TempData["SuccessMessage"] = "Ride Reservation Cancelled";
                _context.Book_Car.Remove(book_Car);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new { User_ID = book_Car.User_ID });
        }

        private bool Book_CarExists(int id)
        {
            return _context.Book_Car.Any(e => e.Booking_Car_ID == id);
        }

        public IActionResult CreateNFA()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Get_Car_ID(int ID, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Car_ID = ID;
            return View("CreateNFA");
        }
        public async Task<IActionResult> Payment(int Car_ID,int User_ID, string First_Name, string Last_Name, string Pickup_Location, string Dropoff, string Pickup_Time , string Contact)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.Car_ID = Car_ID;
            ViewBag.First_Name = First_Name;
            ViewBag.Last_Name = Last_Name;
            ViewBag.Contact = Contact;
            ViewBag.Pickup_Location = Pickup_Location;
            ViewBag.Pickup_Time = Pickup_Time;
            ViewBag.Dropoff = Dropoff;
            return View("Payment");
        }
        public async Task<IActionResult> Cars(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View(await _context.Add_Car.ToListAsync());
        }
    }
}
