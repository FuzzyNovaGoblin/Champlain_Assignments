import 'package:flutter/material.dart';

class IconPicker extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: GridView.count(
        crossAxisCount: 4,
        // itemCount: 11309,
        children:<Widget>[ElevatedButton(style:ElevatedButton.styleFrom(primary: Colors.red) , onPressed: ()=>Navigator.pop(context), child: Text("Cancel"))]+ List<Widget>.generate(
            11309, (index) => FittedBox(fit: BoxFit.contain, child: IconButton(onPressed: () => Navigator.pop(context, IconData(0xe52a + index, fontFamily: 'MaterialIcons')), icon: Icon(IconData(0xe52a + index, fontFamily: 'MaterialIcons'))))),
        // itemBuilder: (context, index) => Icon(IconData(0xe52a + index, fontFamily: 'MaterialIcons')),
      ),
    );
  }
}
