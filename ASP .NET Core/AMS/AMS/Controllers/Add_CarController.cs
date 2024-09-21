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
    public class Add_CarController : Controller
    {
        private readonly ApplicationDbContext _context;

        public Add_CarController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Add_Car
        public async Task<IActionResult> Index(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View(await _context.Add_Car.ToListAsync());
        }

        // GET: Add_Car/Details/5
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var add_Car = await _context.Add_Car
                .FirstOrDefaultAsync(m => m.Car_ID == id);
            if (add_Car == null)
            {
                return NotFound();
            }

            return View(add_Car);
        }

        // GET: Add_Car/Create
        public async Task<IActionResult> Create(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View();
        }

        // POST: Add_Car/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Car_ID,User_ID,Car_Name,First_Name,Last_Name,Driver_Age,Rating,Number_Plate,Contact")] Add_Car add_Car, int User_ID)
        {
            if (ModelState.IsValid)
            {
                _context.Add(add_Car);
                await _context.SaveChangesAsync();
                TempData["SuccessMessage"] = "Added new Car";
                return RedirectToAction(nameof(Index), new { User_ID = add_Car.User_ID });
            }
            return View(add_Car);
        }

        // GET: Add_Car/Edit/5
        public async Task<IActionResult> Edit(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var add_Car = await _context.Add_Car.FindAsync(id);
            if (add_Car == null)
            {
                return NotFound();
            }
            return View(add_Car);
        }

        // POST: Add_Car/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Car_ID,User_ID,Car_Name,First_Name,Last_Name,Driver_Age,Rating,Number_Plate,Contact")] Add_Car add_Car, int User_ID)
        {
            if (id != add_Car.Car_ID)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(add_Car);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!Add_CarExists(add_Car.Car_ID))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                TempData["SuccessMessage"] = "Updated Car Details";
                return RedirectToAction(nameof(Index), new { User_ID = add_Car.User_ID });
            }
            return View(add_Car);
        }

        // GET: Add_Car/Delete/5
        public async Task<IActionResult> Delete(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var add_Car = await _context.Add_Car
                .FirstOrDefaultAsync(m => m.Car_ID == id);
            if (add_Car == null)
            {
                return NotFound();
            }

            return View(add_Car);
        }

        // POST: Add_Car/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id, int User_ID)
        {
            var add_Car = await _context.Add_Car.FindAsync(id);
            if (add_Car != null)
            {
                TempData["DeleteMessage"] = "Removed a Car";
                _context.Add_Car.Remove(add_Car);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new { User_ID = add_Car.User_ID });
        }

        private bool Add_CarExists(int id)
        {
            return _context.Add_Car.Any(e => e.Car_ID == id);
        }
    }
}
