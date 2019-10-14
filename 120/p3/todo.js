let todoList = [];

let today = new Date();


todoList.push({
    completed: false,
    dueDate: today.setDate(today.getDate() + 6),
    text: "Make this app better"
});

todoList.push({
    completed: true,
    dueDate: today.setDate(today.getDate() + 2),
    text: "Sleep"
});

todoList.push({
    completed: true,
    dueDate: today.setDate(today.getDate() + 3),
    text: "Eat"
});

todoList.push({
    completed: false,
    dueDate: today.setDate(today.getDate() + 6),
    text: "Drink"
});

function addTodo() {
    let textField = document.getElementById('newTodo');
    const newTodo = textField.value;

    let dueDateField = document.getElementById('dueDate');
    const dueDate = dueDateField.value;

    todoList.push({
        completed: false,
        dueDate: dueDate,
        text: newTodo,
    });

    dueDateField.value = null;
    textField.value = null;

   console.log(todoList);
   thingyMethod();
}

const thingyMethod = (event) => {
   const listElement = document.getElementById("todo-list");
   while (listElement.firstChild) {
      listElement.removeChild(listElement.firstChild);
   }
   let i = 0;
   todoList.forEach(todoItem => {
      const e = i++;
      let item = document.createElement("li");
      if (todoItem.completed)
         item.innerHTML = `<strike>${todoItem.text}</strike>`;
      else
         item.innerHTML = `<span>${todoItem.text}</span>`;
      item.addEventListener("click", () => { todoItem.completed = !todoItem.completed; thingyMethod(); });
      item.addEventListener("contextmenu", () => { todoList.splice(e, 1); thingyMethod(); return true;});

      listElement.appendChild(item);
   });
}

document.addEventListener('DOMContentLoaded', thingyMethod);
