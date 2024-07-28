import '../features/login/login.dart';
import '../features/register/register.dart';
import '../features/crypto_list/crypto_list.dart';
import '../features/crypto_coin/crypto_coin.dart';
import '../features/profile/profile.dart';


final routes = {
  '/': (context) => const LoginPage(title: 'Login Page'),
  '/register': (context) => const RegisterPage(title: 'Register Page'),
  '/list': (context) => const CryptoListScreen(title: 'Crypto List'),
  '/coin': (context) => const CryptoCoinScreen(),
  '/profile': (context) => const ProfileScreen(title: 'Profile Page'),
};