<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * Localized language
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_db' );

/** Database username */
define( 'DB_USER', 'escu' );

/** Database password */
define( 'DB_PASSWORD', '9999' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',          '@jsuzC^Dbge!:m+=hx;h<nqHRTC!F{{U_6DkR82DA]wYxsd/k1;V%x)`fK%5v#x%' );
define( 'SECURE_AUTH_KEY',   'szn)Y!dwL8ES1&zP6?)rj.YL=E^~_zg@-}*=b;Dn2$fWPEHerV~f:[v,Zg5P?wCU' );
define( 'LOGGED_IN_KEY',     'k;+_sl#Q9J,8+Y?yI@Dw|&&49foU=uoU~ZMhZDX+jfY}Lm@(Qm|zQC$$W`vtS.21' );
define( 'NONCE_KEY',         '_}YfN*sF|YA@)G9tANp(P}Fhfr$O$|r3s*#qbr82{)W{R #])-@,R$nm;gXsqEO^' );
define( 'AUTH_SALT',         'kad_ D~pFl9xcE5agzSTmZ.@~vdLGuq?L>QX9PK+mZ_ZS$i^o2@.<Vql:5?Bp)M5' );
define( 'SECURE_AUTH_SALT',  '%~}6X]>RpH,bq!Bnpl cBYtDVBHO@/RqpQ7Ex1Ax&r#,GQ*(Cd:m|4)FAg?K8&E`' );
define( 'LOGGED_IN_SALT',    '>+^gbWRs6#4KODey(94 Gq:Zp<EKcLlUs|juaerNiF*=:<j7l-q3[_>;gVzQX@J]' );
define( 'NONCE_SALT',        '.]~2eHQsb>Du#*xcj=OW1m/t9[%9?|/e&c[~hpf@.UlUSB60azX~.liTd!wCSqh*' );
define( 'WP_CACHE_KEY_SALT', '`EUHjZ7q^2Q|`zN/EaNhG@tPLZ7O=ompTl=Qi-.NQ3w]Cq?4;0xIG%:/|Ld(YL/,' );


/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';


/* Add any custom values between this line and the "stop editing" line. */



/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
if ( ! defined( 'WP_DEBUG' ) ) {
	define( 'WP_DEBUG', false );
}

define( 'FS_METHOD', 'direct' );
define( 'WP_REDIS_HOST', 'redis' );
define( 'WP_REDIS_PORT', 6379 );
define( 'WP_REDIS_PASSWORD', 'sider' );
/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
