document.addEventListener("DOMContentLoaded", function () {
    document.getElementById("form").addEventListener("submit", function (event) {
        event.preventDefault();

        let valid = true; // Tracks overall validity
        const errorBox = document.getElementById("errorBox");
        errorBox.innerHTML = ""; // Clear previous errors

        // Form fields
        const Fname = document.getElementById("Fname");
        const Lname = document.getElementById("Lname");
        const Address = document.getElementById("Address");
        const PostalCode = document.getElementById("PostalCode");
        const Province = document.getElementById("Province");
        const Age = document.getElementById("Age");
        const Password = document.getElementById("Password");
        const ConfirmPassword = document.getElementById("ConfirmPassword");
        const Email = document.getElementById("Email");

        // Regex patterns
        const Postalregex = /^[a-zA-Z]\d[a-zA-Z]\d[a-zA-Z]\d$/;
        const Provinceregex = /^(QC|ON|MN|SK|AB|BC)$/i;
        const Ageregex = /^(2[0-9]|[3-9][0-9])$/;
        const Emailregex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
        const Passwordregex = /^(?=(?:.*\d){2})(?=(?:.*[A-Z]){2}).{5,}$/;

        // Required fields validation
        const fields = [Fname, Lname, Address, PostalCode, Province, Age, Password, ConfirmPassword, Email];
        fields.forEach((field) => {
            field.addEventListener('input', function () {
                field.setCustomValidity("");
                errorBox.innerHTML = ""; // Clear all error messages when input is detected
            });

            if (!field.value.trim()) {
                field.setCustomValidity(`${field.id} is required.`);
                field.reportValidity();
                errorBox.innerHTML += `${field.id} is required.<br>`;
                valid = false;
            }
        });

        // Field-specific validation
        if (!Postalregex.test(PostalCode.value)) {
            PostalCode.setCustomValidity("Postal Code must be in the format A1A1A1");
            PostalCode.reportValidity();
            errorBox.innerHTML += "Postal Code must be in the format A1A1A1.<br>";
            valid = false;
        }

        if (!Provinceregex.test(Province.value.toUpperCase())) {
            Province.setCustomValidity("Province must be QC, ON, MN, SK, AB, or BC");
            Province.reportValidity();
            errorBox.innerHTML += "Province must be QC, ON, MN, SK, AB, or BC.<br>";
            valid = false;
        }

        if (!Ageregex.test(Age.value)) {
            Age.setCustomValidity("Age must be between 20 and 99");
            Age.reportValidity();
            errorBox.innerHTML += "Age must be between 20 and 99.<br>";
            valid = false;
        }

        if (!Emailregex.test(Email.value)) {
            Email.setCustomValidity("Invalid email format");
            Email.reportValidity();
            errorBox.innerHTML += "Invalid email format.<br>";
            valid = false;
        }

        if (!Passwordregex.test(Password.value)) {
            Password.setCustomValidity("Password must have at least two digits and two uppercase letters");
            Password.reportValidity();
            errorBox.innerHTML += "Password must have at least two digits and two uppercase letters.<br>";
            valid = false;
        }

        if (Password.value !== ConfirmPassword.value) {
            ConfirmPassword.setCustomValidity("Passwords do not match");
            ConfirmPassword.reportValidity();
            errorBox.innerHTML += "Passwords do not match.<br>";
            valid = false;
        }

        // Show errors or success message
        if (!valid) {
            errorBox.style.display = "block";
        } else {
            errorBox.style.display = "none";
            alert("Form submitted successfully!");
        }
    });
});
