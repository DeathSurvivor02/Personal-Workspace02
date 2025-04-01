document.addEventListener("DOMContentLoaded", function () {
    document.getElementById("billShip").addEventListener("submit", function (event) {
        event.preventDefault();

        let realCVC = true;
        let realCard = true;

        const cardName = document.getElementById("cardName");
        const cardNumber = document.getElementById("cardNumber");
        const cvc = document.getElementById("cvc");
        const errorBox = document.getElementById("errorBox");

        if (cardName.value === "") {
            cardName.setCustomValidity("Cardholder Name is required.");
            realCVC = false;
        } else {
            cardName.setCustomValidity("");
        }

        const cardLength = /^\d{16}$/;
        if (!cardLength.test(cardNumber.value)) {
            cardNumber.setCustomValidity("16 Digit Credit Card Number is required.");
            realCard = false;
        } else {
            cardNumber.setCustomValidity("");
        }

        const cvcPattern = /^\d{3}$/;
        if (!cvcPattern.test(cvc.value)) {
            cvc.setCustomValidity("CVC must be a 3-digit number.");
            realCVC = false;
        } else {
            cvc.setCustomValidity("");
        }

        if (!realCVC || !realCard) {
            errorBox.style.display = "block";
        } else {
            errorBox.style.display = "none";
            window.location.href = "confirmation.html";
        }
    });

    document.getElementById("copyPayment").addEventListener("change", function () {
        const cardName2 = document.getElementById("cardName2");
        const cardNumber2 = document.getElementById("cardNumber2");
        const cvc2 = document.getElementById("cvc2");

        if (document.getElementById("copyPayment").checked) {
            cardName2.value = document.getElementById("cardName").value;
            cardNumber2.value = document.getElementById("cardNumber").value;
            cvc2.value = document.getElementById("cvc").value;
        } else {
            cardName2.value = "";
            cardNumber2.value = "";
            cvc2.value = "";
        }
    });
});
