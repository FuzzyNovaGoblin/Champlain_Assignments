import 'package:flutter/material.dart';

class IconPicker extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      floatingActionButton: FloatingActionButton(
        backgroundColor: Colors.white,
        child: Icon(Icons.arrow_back, color: Colors.black,),
        onPressed: () =>Navigator.pop(context),),
      body: GridView.count(
        crossAxisCount: 4,
        // itemCount: 11309,
        // /<Widget>[ElevatedButton(style:ElevatedButton.styleFrom(primary: Colors.red) , onPressed: ()=>Navigator.pop(context), child: Text("Cancel"))]+
        children: List<Widget>.generate(
            11309, (index) => FittedBox(fit: BoxFit.contain, child: IconButton(onPressed: () => Navigator.pop(context, IconData(0xe52a + index, fontFamily: 'MaterialIcons')), icon: Icon(IconData(0xe52a + index, fontFamily: 'MaterialIcons'))))),
        // itemBuilder: (context, index) => Icon(IconData(0xe52a + index, fontFamily: 'MaterialIcons')),
      ),
    );
  }
}
