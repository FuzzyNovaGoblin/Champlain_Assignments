final float SPEED = 0.3;


class Ball {
  float w, x, y, mult, offset;
  String str;
  int fontSize = 0;
  final float r;
  int dir = 1;

  public ArrayList<Ball> children;
  float red, green, blue;
  Ball parent;
  Ball(Ball parent, float w, float r, float offset, String str, int fontSize, float mutAdd, int dir) {
    //this.x = x;
    //this.y = y;
    this.parent = parent;
    this.w = w;
    this.r = r;
    this.dir = dir;
    mult = parent.mult * (1.7 + mutAdd);
    children = new ArrayList();
    this.offset = offset;
    this.str=str;
    do {
      red = random(255);
      green = random(255);
      blue = random(255);
    } while (red+green+blue < 350);
    this.fontSize = fontSize;
  }
  Ball(float x, float y, float w, String str) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.r = 0;
    this.str = str;
    mult = 1;
    children = new ArrayList();
    parent = null;
    fontSize = 40;
    offset = 0;
    red = 255;
    green = 255;
    blue = 255;
  }

  void ballDraw() {
    if (parent != null) {
      float t = millis()/1000.0f*mult;
      t+= offset;
      t *= SPEED;
      t *= dir;
      x = (int)(parent.x+r*cos(t));
      y = (int)(parent.y+r*sin(t));
    }
    fill(red, green, blue);
    circle(x, y, w);
    if (parent == null)
      fill(255-red, 255 - green, 255-blue);
    else
      fill(255, 255, 255);
    textSize(fontSize);
    textAlign(CENTER);
    text(str, x, y+fontSize/3);//, w, fontSize); 

    for (int i = 0; i < children.size(); i++) {
      children.get(i).ballDraw();
    }
  }

  void addChild(float width, float r, float offset, String str, int fontSize, int dir) {
    children.add(new Ball(this, width, width/2 + this.w/2 + r, 1000/SPEED*offset, str, fontSize, 0, dir));
  }
  void addChild(float width, float r, float offset, String str, int fontSize, float mutAdd, int dir) {
    children.add(new Ball(this, width, width/2 + this.w/2 + r, 1000/SPEED*offset, str, fontSize, mutAdd, dir));
  }
}


Ball sun;

void setup() {
  size(1500, 1000);
  sun = new Ball(1500/2.0, 1000/2.0, 200.0, "ME");
  //computers
  sun.addChild(100, 100, 0, "Computers", 20, 1);
  sun.children.get(sun.children.size()-1).addChild(20, 10, 0, "Linux", 12, 3.5, -1);
  sun.children.get(sun.children.size()-1).addChild(55, 35, 1, "Bella", 15, -1);
  sun.children.get(sun.children.size()-1).addChild(50, 40, 2, "Dale", 10, -1);
  sun.children.get(sun.children.size()-1).addChild(46, 33, 3, "Storm", 15, -1);
  sun.children.get(sun.children.size()-1).addChild(50, 40, 4, "Nip", 20, -1);

  //programming
  sun.addChild(135, 150, 2, "Programming", 20, 1);
  sun.children.get(sun.children.size()-1).addChild(50, 50, 0, "C++", 20, 1.5, -1);
  sun.children.get(sun.children.size()-1).addChild(20, 15, 1, "Lisp", 12, 4.5, -1);
  sun.children.get(sun.children.size()-1).addChild(50, 50, 2, "Java", 20, 1.5, -1);
  sun.children.get(sun.children.size()-1).addChild(50, 50, 3, "C#", 20, 1.5, -1);
  sun.children.get(sun.children.size()-1).addChild(50, 50, 4, "Dart", 20, 1.5, -1);
  sun.children.get(sun.children.size()-1).children.get(sun.children.get(sun.children.size()-1).children.size()-1).addChild(30, 10, 4, "Flutter", 20, 1);

  //Family
  sun.addChild(135, 150, 4, "Family", 20, 1);
  sun.children.get(sun.children.size()-1).addChild(60/3, 55, 0, "Father", 14,1.3, 1);
  sun.children.get(sun.children.size()-1).addChild(25/3, 60, 1, "Mom", 10,1.3, 1);
  sun.children.get(sun.children.size()-1).addChild(50/3, 80, 2, "Brother", 17, 1);
  sun.children.get(sun.children.size()-1).addChild(70/3, 10, 3, "Step Mom", 17, 3.5, 1);
  sun.children.get(sun.children.size()-1).addChild(40/3, 80, 4, "Dog", 14, 1);

  //etheics
  sun.addChild(20, 600, 0, "Do Good", 20, 3, 1);
  sun.addChild(20, 600, 3, "Succeed", 20, 3, 1);
  sun.addChild(20, 600, 2, "Be Happy", 20, 3, 1);
  
  
  sun.addChild(20, 5, 30, "Friends", 20, 10, 1);
}

void draw() {
  background(0, 0, 0);
  sun.ballDraw();
}
