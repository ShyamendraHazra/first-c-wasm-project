const CgetString = cwrap('returnString', 'string', ['string', 'number']);
const submitButton = document.querySelector('#submit-button');


Module['onRuntimeInitialized'] = () => {
    
    const name = document.querySelector('#name');
    const welcomeMsg = document.querySelector('#welcome-msg');
    const welcomeMsg1 = document.querySelector('#welcome-msg1');
    
    submitButton.addEventListener('click', () => {
        name.value.length !== 0 ? welcomeMsg.innerText =  CgetString(name.value, name.value.length):welcomeMsg.innerText = "";
        submitButton.style.setProperty('box-shadow', '0px 0px 0px 5px #000');
        setTimeout(function() {
            submitButton.style.setProperty('box-shadow', 'none');
        }, 1500);
  
    });


    const nameOne = document.querySelector('#name-1');

    nameOne.addEventListener('keyup', () => {
        
        nameOne.value.length !== 0 ? welcomeMsg1.innerText = CgetString(nameOne.value, nameOne.value.length):welcomeMsg1.innerText = "";
    });

}


