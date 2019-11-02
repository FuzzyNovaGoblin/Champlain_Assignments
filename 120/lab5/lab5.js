class Book{
   title;
   author;
   listItem;
   read;
   constructor(title, author, read) {
      this.title = title;
      this.author = author;
      this.read = read;
      this.genLi();
   }

   genLi() {
      this.listItem = (this.read) ? `<li><p><s>${this.title} by ${this.author}</s></p></li>` : `<li><p>${this.title} by ${this.author}</p></li>`;
   }
}

books = [
   new Book("book1", "person 1", false),
   new Book("book2", "person 2", true),
   new Book("book3", "person 3", true),
   new Book("book4", "person 4", false),
];

const fillStuff = () => {
   let listEl = document.getElementById("bookListElement");
   let text = "";
   for (let i = 0; i < books.length; i++){
      text += books[i].listItem;
      if (books[i].read) {
         console.log(`You have read ${books[i].title}`)
      }
      else {
         console.log(`You still need to read ${books[i].title}`)
      }
   }
   listEl.innerHTML = text;
}
