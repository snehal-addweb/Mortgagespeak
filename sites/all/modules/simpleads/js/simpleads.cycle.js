/**
 * @file
 * SimpleAds jQuery Cycle JS.
 * More details http://jquery.malsup.com/cycle/options.html
 */

(function ($) {
  Drupal.behaviors.simpleadsCycle = {
    attach: function(context) {

      var simpleads = $("div[data-fx]");

      simpleads.each(function(i){

        var _fx = $(this).attr('data-fx');
        var _speed = $(this).attr('data-speed');
        var _total = $(this).find('.simpleads-item').size();
        var _item = $(this).find('.simpleads-item');

        $(this).cycle({
          fx: _fx, // scrollUp, fade, shuffle, zoom,  turnDown
          speed: _speed,
          before: _onBefore,
          startingSlide: Math.floor((Math.random() * _total))
        });

        _item.bind('click', function(){
          var advertisementID = $(this).attr('data-id');
          _callback(advertisementID, 'click');
        });

        if ( _total == 1 ) {
          _callback(_item.attr('data-id'), 'impression');
        }

      });

	    function _onBefore(curr, next, opts){
        var advertisementID = $(this).attr('data-id');
        _callback(advertisementID, 'impression');
      }

      function _callback(advertisementID, type) {
        $.post(Drupal.settings.basePath + '?q=node/' + advertisementID + '/stats/' + type);
      }

    }
  };
}(jQuery));