class Book{
   title;
   author;
   read;
   imgUrl;
   constructor(title, author, read, imgUrl) {
      this.title = title;
      this.author = author;
      this.read = read;
      this.imgUrl = imgUrl;
      this.genLi();
   }

   genLi(index) {
      return `<li onclick="books[${index}].read = !(books[${index}].read); fillStuff();  "><p>` + ((this.read) ? "<s>" : "") + `${this.title} by ${this.author}` + ((this.read) ? "</s>" : "")+`</p>`+ (this.imgUrl? `<img width="50" src="${this.imgUrl}"/>` : ``) + `</li>`;
   }
}

books = [
   new Book("The Hobbit", "J.R.R. Tolkien", false, "https://external-content.duckduckgo.com/iu/?u=http%3A%2F%2Fecx.images-amazon.com%2Fimages%2FI%2F6113XDPUrVL._SY344_BO1%2C204%2C203%2C200_.jpg&f=1&nofb=1"),
   new Book("book1", "person 1", false, ""),
   new Book("book2", "person 2", true, ""),
   new Book("book3", "person 3", true, ""),
   new Book("book4", "person 4", false, ""),
];

const fillStuff = () => {
   let listEl = document.getElementById("bookListElement");
   let text = "";
   for (let i = 0; i < books.length; i++){
      text += books[i].genLi(i);
      if (books[i].read) {
         console.log(`You have read ${books[i].title}`)
      }
      else {
         console.log(`You still need to read ${books[i].title}`)
      }
   }
   listEl.innerHTML = text;
}
