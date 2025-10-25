document.addEventListener('DOMContentLoaded', function() {

    // =======================
    // 1. Current Year Display
    // =======================
    (function updateYear() {
        const yearEl = document.getElementById('year');
        if (yearEl) yearEl.textContent = new Date().getFullYear();
    })();

    // =======================
    // 2. Calendar Generator
    // =======================
    (function renderCalendar() {
        const cal = document.getElementById('cal');
        if (!cal) return;

        const today = new Date();
        const year = today.getFullYear();
        const month = today.getMonth();
        const first = new Date(year, month, 1);
        const last = new Date(year, month + 1, 0);

        // Adjust startDay for Monday start (0=Sunday, 1=Monday, ..., 6=Saturday)
        const startDay = (first.getDay() + 6) % 7; 
        const totalDays = last.getDate();

        // P, S, Ç, P, C, C, P (Pazartesi, Salı, Çarşamba, Perşembe, Cuma, Cumartesi, Pazar)
        const headers = ['Pzt', 'Sal', 'Çar', 'Per', 'Cum', 'Cmt', 'Paz']; 
        
        let html = `<thead><tr>${headers.map(h => `<th>${h}</th>`).join('')}</tr></thead><tbody>`;

        let day = 1;
        let rowCount = 0;
        
        while (day <= totalDays || rowCount === 0) {
            html += '<tr>';
            for (let c = 0; c < 7; c++) {
                if ((rowCount === 0 && c < startDay) || day > totalDays) {
                    html += '<td></td>';
                } else if (day <= totalDays) {
                    const isToday = day === today.getDate() && month === today.getMonth() && year === today.getFullYear();
                    html += `<td class="${isToday ? 'today' : ''}">${day}</td>`;
                    day++;
                }
            }
            html += '</tr>';
            rowCount++;
            // Stop after the last day is included
            if (day > totalDays && rowCount > 0) break; 
        }

        html += '</tbody>';
        cal.innerHTML = html;
    })();


    // ==================================
    // 3. Language Selector Flag Update
    // ==================================
    (function handleLanguageSelector() {
        const languageSelect = document.querySelector('.language-selector select');

        if (languageSelect) {
            // Set initial value so the default flag shows up on page load
            languageSelect.setAttribute('value', languageSelect.value);

            // Add event listener to update the 'value' attribute on change.
            // This is what the CSS targets to change the flag.
            languageSelect.addEventListener('change', function() {
                this.setAttribute('value', this.value);
            });
        }
    })();


    // =======================
    // 4. Dropdown Menu System (Generic)
    // =======================
    (function handleDropdowns() {
        const navItems = document.querySelectorAll('.nav-item'); 

        navItems.forEach(item => {
            const btn = item.querySelector('.nav-btn');
            if (btn) {
                btn.addEventListener('click', e => {
                    e.stopPropagation(); 
                    navItems.forEach(i => {
                        if (i !== item) i.classList.remove('active');
                    });
                    item.classList.toggle('active');
                });
            }
        });

        document.addEventListener('click', () => {
            navItems.forEach(i => i.classList.remove('active'));
        });
    })();

    // =======================
    // 5. Dark Mode Toggle
    // =======================
    (function setupDarkMode() {
        const toggleButton = document.getElementById('darkModeToggle');
        const body = document.body;
        
        if (!toggleButton) return;

        // Function to set the theme and update the button icon
        function setTheme(isDark) {
            if (isDark) {
                body.classList.add('dark-theme');
                localStorage.setItem('theme', 'dark');
                toggleButton.textContent = '☀️'; // Sun icon for dark mode
            } else {
                body.classList.remove('dark-theme');
                localStorage.setItem('theme', 'light');
                toggleButton.textContent = '🌙'; // Moon icon for light mode
            }
        }

        // Initialize Theme: Check saved preference or system preference
        const savedTheme = localStorage.getItem('theme');
        const prefersDark = window.matchMedia('(prefers-color-scheme: dark)').matches;

        if (savedTheme === 'dark') {
            setTheme(true);
        } else if (savedTheme === 'light') {
            setTheme(false);
        } else if (prefersDark) {
            // Use system preference if no preference is saved
            setTheme(true);
        } else {
            // Default to light
            setTheme(false);
        }

        // Event Listener: Handle button click to toggle the theme
        toggleButton.addEventListener('click', () => {
            const isCurrentlyDark = body.classList.contains('dark-theme');
            setTheme(!isCurrentlyDark);
        });
    })();


    // ===================================
    // 6. Location Selector Dropdown Toggle
    // ===================================
    (function handleLocationDropdown() {
        const locationSelector = document.getElementById('locationSelector');
        
        if (!locationSelector) return;

        const dropdownArrow = locationSelector.querySelector('.dropdown-arrow');

        locationSelector.addEventListener('click', function(e) {
            e.stopPropagation(); 
            
            // Toggle the 'active' class to show/hide the menu
            this.classList.toggle('active');

            // Toggle the 'rotated' class on the arrow
            if (dropdownArrow) {
                dropdownArrow.classList.toggle('rotated');
            }
        });
        
        // Close the menu if the user clicks anywhere else on the page
        document.addEventListener('click', () => {
             // Remove 'active' and 'rotated' when closing globally
             locationSelector.classList.remove('active');
             if (dropdownArrow) {
                dropdownArrow.classList.remove('rotated');
             }
        });

        // Prevent clicking inside the dropdown from closing it immediately
        const dropdownMenu = locationSelector.querySelector('.location-dropdown-menu');
        if (dropdownMenu) {
            dropdownMenu.addEventListener('click', e => {
                e.stopPropagation();
            });
        }
    })();


});