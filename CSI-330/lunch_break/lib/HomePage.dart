import 'package:flutter/material.dart';
import 'package:lunch_break/Views/MainView.dart';
import 'package:lunch_break/Views/SettingsView.dart';
import 'package:window_size/window_size.dart';

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    setWindowMinSize(Size(574.0,1050.0));
    setWindowMaxSize(Size(574.0,1050.0));

    return DefaultTabController(
      // initialIndex: 1,

      length: 3,
      initialIndex: 1,
      child: Scaffold(
        bottomNavigationBar:

        TabBar(
          indicatorSize: TabBarIndicatorSize.tab,

           tabs: [
             Icon(Icons.map,size: 50, color: Colors.black,),
             Icon(Icons.face,size: 50, color: Colors.black,),
             Icon(Icons.settings,size: 50,color:Colors.black),
           ],
        ),

        body: TabBarView(
          children: [Placeholder(), MainView(), SettingsView()],
        ),
      ),
    );
  }
}
