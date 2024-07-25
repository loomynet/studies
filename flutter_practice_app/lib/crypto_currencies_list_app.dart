import 'package:flutter/material.dart';
import 'package:flutter_practice_app/router/router.dart';
import 'package:flutter_practice_app/theme/theme.dart';

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Ctypto App',
      theme: theme,
      routes: routes,
    );
  }
}