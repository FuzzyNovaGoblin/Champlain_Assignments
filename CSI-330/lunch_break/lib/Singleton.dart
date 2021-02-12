import 'package:lunch_break/Data/UserDataModel.dart';

class Singleton {
  static final Singleton _singletonRef = Singleton._internal();
  Singleton._internal();

  factory Singleton() => _singletonRef;

  List<UserData> users = List.filled(20, UserData.defaultuser(), growable: true);
  List<String> names = ["Liam" ,	"Olivia",	"Noah", 	"Emma",	"Oliver", 	"Ava",	"William", 	"Sophia",	"Elijah", 	"Isabella",	"James", 	"Charlotte",	"Benjamin", 	"Amelia",	"Lucas", 	"Mia",	"Mason", 	"Harper", 	"Ethan", 	"Evelyn"];
}
