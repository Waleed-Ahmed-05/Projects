using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using AMS.Data;
using AMS.Models;
using Microsoft.VisualStudio.Web.CodeGenerators.Mvc.Templates.BlazorIdentity.Pages.Manage;

namespace AMS.Controllers
{
    public class Contact_usController : Controller
    {
        private readonly ApplicationDbContext _context;

        public Contact_usController(ApplicationDbContext context)
        {
            _context = context;
        }

        // GET: Contact_us
        public async Task<IActionResult> Index(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View(await _context.Contact_us.ToListAsync());
        }

        // GET: Contact_us/Details/5
        public async Task<IActionResult> Details(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var contact_us = await _context.Contact_us
                .FirstOrDefaultAsync(m => m.Contact_ID == id);
            if (contact_us == null)
            {
                return NotFound();
            }

            return View(contact_us);
        }

        // GET: Contact_us/Create
        public async Task<IActionResult> CreateNFA(int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            return View();
        }


        // POST: Contact_us/Create
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Contact_ID,User_ID,First_Name,Last_Name,Phone,Email_ID,Subject,Message")] Contact_us contact_us)
        {
            if (ModelState.IsValid)
            {
                _context.Add(contact_us);
                await _context.SaveChangesAsync();
                TempData["SuccessMessage"] = "Feedback sent successfully";
                return RedirectToAction(nameof(CreateNFA), new { User_ID = contact_us.User_ID });
            }
            return View(contact_us);
        }

        // GET: Contact_us/Edit/5
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var contact_us = await _context.Contact_us.FindAsync(id);
            if (contact_us == null)
            {
                return NotFound();
            }
            return View(contact_us);
        }

        // POST: Contact_us/Edit/5
        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see http://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(int id, [Bind("Contact_ID,First_Name,Last_Name,Phone,Email_ID,Subject,Message")] Contact_us contact_us)
        {
            if (id != contact_us.Contact_ID)
            {
                return NotFound();
            }

            if (ModelState.IsValid)
            {
                try
                {
                    _context.Update(contact_us);
                    await _context.SaveChangesAsync();
                }
                catch (DbUpdateConcurrencyException)
                {
                    if (!Contact_usExists(contact_us.Contact_ID))
                    {
                        return NotFound();
                    }
                    else
                    {
                        throw;
                    }
                }
                return RedirectToAction(nameof(Index));
            }
            return View(contact_us);
        }

        // GET: Contact_us/Delete/5
        public async Task<IActionResult> Delete(int? id, int User_ID)
        {
            var Data = await _context.Users.Where(u => u.User_ID == User_ID).FirstOrDefaultAsync();
            ViewBag.Data = Data;
            if (id == null)
            {
                return NotFound();
            }

            var contact_us = await _context.Contact_us
                .FirstOrDefaultAsync(m => m.Contact_ID == id);
            if (contact_us == null)
            {
                return NotFound();
            }

            return View(contact_us);
        }

        // POST: Contact_us/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id, int User_ID)
        {
            var contact_us = await _context.Contact_us.FindAsync(id);
            if (contact_us != null)
            {
                TempData["DeleteMessage"] = "Removed a feedback";
                _context.Contact_us.Remove(contact_us);
            }

            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index), new { User_ID });
        }

        private bool Contact_usExists(int id)
        {
            return _context.Contact_us.Any(e => e.Contact_ID == id);
        }
    }
}
