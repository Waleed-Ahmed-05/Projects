using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using AMS.Data;
using AMS.Models;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory.Model;
using static System.Collections.Specialized.BitVector32;
using System.Numerics;
using Microsoft.Identity.Client;

namespace AMS.Controllers
{
    public class Add_FlightController : Controller
    {
        private readonly ApplicationDbContext _context;

        public Add_FlightController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Add_Flight
        public async Task<IActionResult> Index(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View(await _context.Add_Flight.ToListAsync());
        }

        // GET: Add_Flight/Details/5
        public async Task<IActionResult> Details(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var add_Flight = await _context.Add_Flight
                .FirstOrDefaultAsync(m => m.Flight_ID == id);
            if (add_Flight == null)
            {
                return NotFound();
            }

            return View(add_Flight);
        }

        // GET: Add_Flight/Create
        public async Task<IActionResult> Create(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View();
        }

        // POST: Add_Flight/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Flight_ID,User_ID,Departing_From,Arrival_At,Departing_Date_01,Arrival_Date_01,Departing_Time_01,Arrival_Time_01,Departing_Date_02,Arrival_Date_02,Departing_Time_02,Arrival_Time_02,Ticket_Price,Class,Status")] Add_Flight add_Flight, int User_ID)
        {
            if (ModelState.IsValid)
            {
                _context.Add(add_Flight);
                await _context.SaveChangesAsync();
                TempData["SuccessMessage"] = "Successfully added a new flight";
                return RedirectToAction(nameof(Index), new { User_ID = add_Flight.User_ID });
            }
            return View(add_Flight);
        }

        // GET: Add_Flight/Edit/5
        public async Task<IActionResult> Edit(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var add_Flight = await _context.Add_Flight.FindAsync(id);
            ViewBag.Status = add_Flight.Status;
            if (add_Flight == null)
            {
                return NotFound();
            }
            return View(add_Flight);
        }

        // POST: Add_Flight/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Flight_ID,User_ID,Departing_From,Arrival_At,Departing_Date_01,Arrival_Date_01,Departing_Time_01,Arrival_Time_01,Departing_Date_02,Arrival_Date_02,Departing_Time_02,Arrival_Time_02,Ticket_Price,Class,Status")] Add_Flight add_Flight)
        {
            if (id != add_Flight.Flight_ID)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(add_Flight);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!Add_FlightExists(add_Flight.Flight_ID))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                TempData["SuccessMessage"] = "Updated flight details successfully";
                return RedirectToAction(nameof(Index), new { User_ID = add_Flight.User_ID });
            }
            return View(add_Flight);
        }

        // GET: Add_Flight/Delete/5
        public async Task<IActionResult> Delete(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var add_Flight = await _context.Add_Flight
                .FirstOrDefaultAsync(m => m.Flight_ID == id);
            if (add_Flight == null)
            {
                return NotFound();
            }

            return View(add_Flight);
        }

        // POST: Add_Flight/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id, int User_ID)
        {
            var add_Flight = await _context.Add_Flight.FindAsync(id);
            if (add_Flight != null)
            {
                TempData["DeleteMessage"] = "Flight removed successfully";
                _context.Add_Flight.Remove(add_Flight);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new { User_ID = add_Flight.User_ID });
        }

        private bool Add_FlightExists(int id)
        {
            return _context.Add_Flight.Any(e => e.Flight_ID == id);
        }





        // Custom built-in functions
        public async Task<IActionResult> Search(IEnumerable<Add_Flight> search_Flight, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            var data = _context.Add_Flight.ToList();
            ViewBag.Departure = data.Select(f => f.Departing_From).Distinct().ToList();
            ViewBag.Arrival = data.Select(f => f.Arrival_At).Distinct().ToList();
            ViewBag.Date = data.Select(f => f.Departing_Date_01).Distinct().ToList();
            ViewBag.Class = data.Select(f => f.Class).Distinct().ToList();
            ViewBag.Status = data.Select(f => f.Status).Distinct().ToList();
            return View();
        }
        public async Task<IActionResult> Round_About(int User_ID,string Departing_From, string Arrival_At, string Departing_Time_01, string Arrival_Time_01, string Departing_Date_01, string Arrival_Date_01, string Ticket_Price, string Class, string Status)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.User_ID = User_ID;
            ViewBag.Departing_From = Departing_From;
            ViewBag.Arrival_At = Arrival_At;
            ViewBag.Departing_Time_01 = Departing_Time_01;
            ViewBag.Arrival_Time_01 = Arrival_Time_01;
            ViewBag.Departing_Date_01 = Departing_Date_01;
            ViewBag.Arrival_Date_01 = Arrival_Date_01;
            ViewBag.Ticket_Price = Ticket_Price;
            ViewBag.Class = Class;
            ViewBag.Status = Status;
            if (Status == "One Way" || Status == "Two Way")
            {
                return View("Submission");
            }
            return NotFound();
        }
        public async Task<IActionResult> Search_01(int User_ID, string Departure, string Arrival, string Date, string Class, string Status, string Adult_Seats)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            // 1 Entry Search 
            //if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_Date_01.Contains(Date)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //// 2 Entry Search
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Departing_Date_01.Contains(Date)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Class.Contains(Class)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Class.Contains(Class)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //// 3 Entry Search
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Status.Contains(Status)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //// 4 Entry Search
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //else if (!string.IsNullOrEmpty(Departure) && string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && !string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).Where(j => j.Status.Contains(Status)).ToListAsync());
            //}
            //// 6 Entry Search
            //else if (!string.IsNullOrEmpty(Departure) && !string.IsNullOrEmpty(Arrival) && !string.IsNullOrEmpty(Date) && !string.IsNullOrEmpty(Class) && !string.IsNullOrEmpty(Status) && string.IsNullOrEmpty(Adult_Seats))
            //{
            //    return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).Where(j => j.Adult_Seats.Contains(Adult_Seats)).ToListAsync());
            //}
            // 0 Entry Search
            var Flights = await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync();
            if (Flights == null || !Flights.Any())
            {
                TempData["DeleteMessage"] = "No Flights Found";
                return RedirectToAction("Search", new { ViewBag.Data.User_ID });
            }
            return View("IndexNFA", await _context.Add_Flight.Where(j => j.Departing_From.Contains(Departure)).Where(j => j.Arrival_At.Contains(Arrival)).Where(j => j.Departing_Date_01.Contains(Date)).Where(j => j.Class.Contains(Class)).Where(j => j.Status.Contains(Status)).ToListAsync());
        }
        public async Task<IActionResult> Round_About_Data(string Flight_ID,int User_ID,string Departing_From, string Arrival_At, string Departing_Time_01, string Arrival_Time_01, string Departing_Date_01, string Arrival_Date_01, string Departing_Time_02, string Arrival_Time_02, string Departing_Date_02, string Arrival_Date_02, string Ticket_Price, string Class, string Status, string Adult_Seats)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            ViewBag.User_ID = User_ID;
            ViewBag.Flight_ID = Flight_ID;
            ViewBag.Departing_From = Departing_From;
            ViewBag.Arrival_At = Arrival_At;
            ViewBag.Departing_Time_01 = Departing_Time_01;
            ViewBag.Arrival_Time_01 = Arrival_Time_01;
            ViewBag.Departing_Date_01 = Departing_Date_01;
            ViewBag.Arrival_Date_01 = Arrival_Date_01;
            ViewBag.Departing_Time_02 = Departing_Time_02;
            ViewBag.Arrival_Time_02 = Arrival_Time_02;
            ViewBag.Departing_Date_02 = Departing_Date_02;
            ViewBag.Arrival_Date_02 = Arrival_Date_02;
            ViewBag.Ticket_Price = Ticket_Price;
            ViewBag.Class = Class;
            ViewBag.Status = Status;
            return View("Update");
        }
    }
}
