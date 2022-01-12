# Cross-Buy plug-in for Unreal Engine 4

Game Commerce plug-in is a set of classes and methods that you can integrate into your Unity app to work with Xsolla products.

After integration of the plug-in, you can use:

*   [Login](https://developers.xsolla.com/doc/login/) to authenticate users and manage the friend system and user account
*   [In-Game Store](https://developers.xsolla.com/doc/in-game-store/) to manage player’s inventory

The plug-in is suitable if your application is published on a platform that cannot use Xsolla solutions for payments and in-game store for some reason.

![Cross Buy demo](https://i.imgur.com/sschstq.png "Cross Buy demo")

<div style="background-color: WhiteSmoke">
<p><b>Note:</b></p> 
<p>
Cross-Buy plug-in is already included as part of the <a href="https://www.unrealengine.com/marketplace/en-US/product/xsolla-store-sdk">Game Commerce</a> plug-in. You can download the Game Commerce if you need a broader set of features.
</p>
<p>
Cross-Buy plug-in includes <a href="https://www.unrealengine.com/marketplace/en-US/product/xsolla-login-sdk">Login & Account System</a> plug-in.
</p>
<p>
Do <b>NOT</b> install these plug-ins separately.
</p>
</div>

For a better understanding of which Xsolla plug-in to choose, use the table:

<table>
  <tr>
   <td>
   </td>
   <td style="text-align: center"><b>Game Commerce plug-in</b>
   </td>
   <td style="text-align: center"><b>Login & Account System plug-in</b>
   </td>
   <td><b>Cross-Buy plug-in</b>
   </td>
  </tr>
  <tr>
   <td colspan="4" ><strong>In-game store</strong>
   </td>
  </tr>
  <tr>
   <td>
    Virtual currency
   </td>
   <td>+
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    Virtual items
   </td>
   <td>+
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    Player inventory
   </td>
   <td>+
   </td>
   <td>
   </td>
   <td>+
   </td>
  </tr>
  <tr>
   <td>
    Bundles
   </td>
   <td>+
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>
    Promotional campaigns
   </td>
   <td>+
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td colspan="4" ><strong>Login</strong>
   </td>
  </tr>
  <tr>
   <td>
    Authentication
   </td>
   <td>+
   </td>
   <td>+
   </td>
   <td>+
   </td>
  </tr>
  <tr>
   <td>
    User management
   </td>
   <td>+
   </td>
   <td>+
   </td>
   <td>+
   </td>
  </tr>
  <tr>
   <td><strong>Payment UI</strong>
   </td>
   <td>+
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td colspan="4" ><strong>Additional features</strong>
   </td>
  </tr>
  <tr>
   <td>
    UI builder
   </td>
   <td>
    +
   </td>
   <td>
    +
   </td>
   <td>
    +
   </td>
  </tr>
  <tr>
   <td>
    Battle pass
   </td>
   <td>
    +
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
</table>


## Requirements

### System requirements

*   64-bit OS
*   Windows 7 and later
*   macOS 10.13.6 and later
*   XCode 11.1 and later (for macOS)
*   Visual Studio 2017 and later
*   Unreal Engine 4.25 and later

### Target OS

*   iOS
*   Android
*   macOS
*   Windows 64-bit

<div style="background-color: WhiteSmoke">
<p><b>Note:</b> To modify the SDK for your application specifics, follow the <a href="https://developers.xsolla.com/sdk/unreal-engine/how-tos/other/#unreal_engine_sdk_how_to_modify_sdk">SDK modification instruction</a>.</p></div>

## Integration

Before you integrate the plug-in, you need to sign up to [Publisher Account](https://publisher.xsolla.com/signup?store_type=sdk) and set up a new project.

More instructions are on the [Xsolla Developers portal](https://developers.xsolla.com/sdk/unreal-engine/cross-buy/).

## Usage 

Xsolla provides APIs to work with it’s products. The Game Commerce plug-in provides classes and methods for API calls, so you won’t need to write boilerplate code. Use the [tutorials](https://developers.xsolla.com/sdk/unreal-engine/tutorials/) to learn how you can use the [plug-in methods](https://developers.xsolla.com/sdk-code-references/unreal-store/).


## Legal info

[Explore legal information](https://developers.xsolla.com/sdk/unreal-engine/cross-buy/get-started/#sdk_legal_compliance) that helps you work with Xsolla.

Xsolla offers the necessary tools to help you build and grow your gaming business, including personalized support at every stage. The terms of payment are determined by the contract that can be signed via Publisher Account.

**The cost of using all Xsolla products is 5% of the amount you receive for the sale of the game and in-game goods via Xsolla Pay Station**. If you do not use Xsolla Pay Station in your application, but use other products, contact your Account Manager to clarify the terms and conditions.

---

### License

See the [LICENSE](https://github.com/xsolla/inventory-ue4-sdk/blob/master/LICENSE.txt) file.

### Community

[Join our Discord server](https://discord.gg/auNFyzZx96) and connect with the Xsolla team and developers who use Xsolla products.

### Additional resources

*   [Xsolla official website](https://xsolla.com/)
*   [Developers documentation](https://developers.xsolla.com/sdk/unreal-engine/)
*   [Code reference](https://developers.xsolla.com/sdk-code-references/unreal-store/)
*   API reference:
    *   [Login API](https://developers.xsolla.com/login-api/) 
    *   [Commerce API](https://developers.xsolla.com/commerce-api/player-inventory)