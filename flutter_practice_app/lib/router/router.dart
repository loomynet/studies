import 'package:flutter_practice_app/features/crypto_coin/view/crypto_coin_screen.dart';
import 'package:flutter_practice_app/features/crypto_list/view/crypto_list_screen.dart';
import 'package:flutter_practice_app/features/login_page/login_page.dart';
import 'package:flutter_practice_app/features/register_page/register_page.dart';

final routes = {
  '/': (context) => const LoginPage(title: 'Login Page'),
  '/register': (context) => const RegisterPage(title: 'Register Page'),
  '/list': (context) => const CryptoListScreen(title: 'Crypto List'),
  '/coin': (context) => const CryptoCoinScreen(),
};