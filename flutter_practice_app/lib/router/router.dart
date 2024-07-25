import 'package:flutter_practice_app/features/crypto_coin/view/crypto_coin_screen.dart';
import 'package:flutter_practice_app/features/crypto_list/view/crypto_list_screen.dart';

final routes = {
  '/': (context) => const CryptoListScreen(title: 'Home Page'),
  '/coin': (context) => const CryptoCoinScreen(),
};