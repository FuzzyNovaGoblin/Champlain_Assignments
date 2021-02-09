import 'package:flutter/material.dart';

class VisableOnMapButton extends StatefulWidget {
  @override
  _VisableOnMapButtonState createState() => _VisableOnMapButtonState();
}

class _VisableOnMapButtonState extends State<VisableOnMapButton> {
  bool vis = true;
  @override
  Widget build(BuildContext context) {
    return ElevatedButton(
      onPressed: ()=>setState(()=>vis = !vis),
      style:ButtonStyle(backgroundColor: Colors.) ,
      child: FittedBox(fit: BoxFit.cover, child: Text( vis?"Visable On Map":"Invisable On Map", style: TextStyle(fontSize: 100))),
    );
  }
}