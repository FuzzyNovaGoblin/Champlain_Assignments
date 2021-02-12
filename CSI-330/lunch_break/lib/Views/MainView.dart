import 'package:flutter/material.dart';
import 'package:lunch_break/Singleton.dart';
import 'package:lunch_break/UIParts/UserSpan.dart';
import 'package:window_size/window_size.dart';

class MainView extends StatefulWidget {
  @override
  _MainViewState createState() => _MainViewState();
}

class _MainViewState extends State<MainView> {
  @override
  Widget build(BuildContext context) {
    getWindowInfo().then((v) => print("screen info:\n$v\n${v.frame}\n${v.scaleFactor}"));

    return ListView.builder(
      itemCount: Singleton().users.length,
      itemBuilder: (context, index) => SizedBox(child: UserSpan(Singleton().users[index])),
    );
  }
}
