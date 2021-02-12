import 'package:flutter/material.dart';
import 'package:lunch_break/Singleton.dart';

class VisableOnMapButton extends StatefulWidget {
  final Function callback;

  const VisableOnMapButton({Key key, @required this.callback}) : super(key: key);
  @override
  _VisableOnMapButtonState createState() => _VisableOnMapButtonState();
}

class _VisableOnMapButtonState extends State<VisableOnMapButton> {
  @override
  Widget build(BuildContext context) {
    return ElevatedButton(
      onPressed: () => setState(() => widget.callback()),
      style: ButtonStyle(
        backgroundColor: MaterialStateProperty.resolveWith<Color>(
          (Set<MaterialState> states) {
            if (states.contains(MaterialState.pressed)) return Colors.grey.withOpacity(0.5);
            return Singleton().users[0].enableMaps ? Colors.white : Colors.black; // Use the component's default.
          },
        ),
      ),
      child: FittedBox(
          fit: BoxFit.cover,
          child: Padding(
            padding: const EdgeInsets.symmetric(vertical: 20),
            child: Text(Singleton().users[0].enableMaps ? "Visable On Map" : "Invisable On Map", style: TextStyle(fontSize: 100, color: Singleton().users[0].enableMaps ? Colors.black : Colors.white)),
          )),
    );
  }
}
