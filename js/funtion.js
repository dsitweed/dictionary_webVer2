// file json - data
const url = "./text/data.json";

const searchInput = document.querySelector('#search-input');
const result = document.querySelector('#result');

searchInput.addEventListener('change', (e) => {
    console.log(searchInput.value);
    doGetJSON(url, searchInput.value);
});


function doGetJSON(url, inputWord) {
    //link database
    fetch(url)
        .then(async response => {
            if (!response.ok) {
                throw new Error("Error, stattus = " + response.status);
            }
            const data = await response.json();
            console.log("data: ", data);
            // Neu data gui la chu hoa nhugng tim bang chu thuong thi sao
            //search word (inputWord) in database
            const check = data.find(function(e) {
                const compare = String(e.word).toLocaleLowerCase();
                if (inputWord.toLocaleLowerCase() == compare) {
                    console.log('[Data from database]: ', e.word);
                    console.log('[Data search]: ', inputWord);
                    result.innerHTML = e.mean;
                    return 1;
                }
            });
            console.log("typeof result: ", check);
            if (check === undefined)
                result.innerHTML = "Can't find!";

        })
        .catch(error => {
            console.log(error);
        })
}