import 'package:flutter_practice_app/features/crypto_coin/view/crypto_coin_screen.dart';
import 'package:flutter_practice_app/features/crypto_list/view/crypto_list_screen.dart';
import 'package:flutter_practice_app/features/login/login.dart';
import 'package:flutter_practice_app/features/register/register.dart';
import 'package:flutter_practice_app/features/profile/profile.dart';

final routes = {
  '/': (context) => const LoginPage(title: 'Login Page'),
  '/register': (context) => const RegisterPage(title: 'Register Page'),
  '/list': (context) => const CryptoListScreen(title: 'Crypto List'),
  '/coin': (context) => const CryptoCoinScreen(),
  '/profile': (context) => const ProfileScreen(title: 'Profile Page'),
};