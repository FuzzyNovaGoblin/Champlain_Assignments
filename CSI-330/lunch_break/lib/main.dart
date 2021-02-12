import 'package:flutter/material.dart';
import 'package:lunch_break/Data/UserDataModel.dart';
import 'package:lunch_break/HomePage.dart';
import 'package:lunch_break/Singleton.dart';
import 'package:window_size/window_size.dart';

MaterialApp baseApp = MaterialApp(
  home: HomePage(),
);

void main() {
  for (int i = 0; i < 20; i++) {
    Singleton().users[i] = UserData.defaultuser();
    Singleton().users[i].picUrl = "assets/images/${i + 1}.png";
    Singleton().users[i].name = Singleton().names[i];
  }
  Singleton().users[0].statusTxt = "at a party";
  Singleton().users[0].detailsTxt = "come down to 704 west vill ave, this place is great";
  Singleton().users[1].statusTxt = "just chillin";
  Singleton().users[2].statusTxt = "ughh work chillin";


  runApp(baseApp);
}
