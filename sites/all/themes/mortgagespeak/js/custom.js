jQuery(document).ready(function(){jQuery('input[type="radio"], input[type="checkbox"]').wrap('<div class="input-rc"></div>'),jQuery(".input-rc").append('<span class="input-rc-span"></span>');var e=window.location.pathname;"/user"==e&&(jQuery(".tabs--primary").find('a[href="/user/register"]').addClass("hide-register"),jQuery(".tabs--primary").find('a[href="/user/password"]').addClass("hide-pass")),jQuery("#edit-select-all--2").change(function(){var e=this.checked;1==e?jQuery(".field-type-taxonomy-term-reference #edit-field-news-topics-und--2 .form-type-checkbox .form-checkbox").prop("checked",!0):jQuery(".field-type-taxonomy-term-reference #edit-field-news-topics-und--2 .form-type-checkbox .form-checkbox").prop("checked",!1)}),jQuery(".page-my-page-tracked-companies ul.menu li:nth-child(2)").addClass("active-trail active"),jQuery(".page-my-page-tracked-companies ul.menu li:nth-child(2) a").addClass("active-trail active"),jQuery(".page-my-page-saved-articles ul.menu li:nth-child(2)").addClass("active-trail active"),jQuery(".page-my-page-saved-articles ul.menu li:nth-child(2) a").addClass("active-trail active"),jQuery("body").click(function(){jQuery(".views-popup-container").removeClass("open-popup")}),jQuery(".views-popup-container").click(function(e){e.stopPropagation()}),jQuery(".content-lists .content-list > .views-field-title").click(function(e){e.stopPropagation(),jQuery(this).parent().children(".content-lists .content-list .views-popup-container").hasClass("open-popup")?jQuery(this).parent().children(".open-popup").removeClass("open-popup"):(jQuery(".content-lists .content-list .views-popup-container").removeClass("open-popup"),jQuery(this).parent().children(".content-lists .content-list .views-popup-container").addClass("open-popup"))}),jQuery(".views-popup-container .popup-header .close-popup").click(function(){jQuery(".content-lists .content-list .views-popup-container").removeClass("open-popup")}),jQuery(document).keydown(function(e){27==e.keyCode&&jQuery(".views-popup-container").removeClass("open-popup")}),jQuery(".click-title").click(function(e){e.stopPropagation(),jQuery(this).parents(".views-row").children(".views-popup-container").hasClass("open-popup")?jQuery(this).parents(".views-row").children(".open-popup").removeClass("open-popup"):(jQuery(".views-popup-container").removeClass("open-popup"),jQuery(this).parents(".views-row").children(".views-popup-container").addClass("open-popup"))}),jQuery(".views-popup-container .popup-header .close-popup").click(function(){jQuery(".views-popup-container").removeClass("open-popup")}),jQuery('input[type="file"]').wrap('<div class="input-file"><div class="input-file-sub"></div></div>'),jQuery(".input-file").append('<span class="input-file-name">No file chosen</span>'),jQuery(".input-file-sub input").change(function(){var e=jQuery(this).val();jQuery(this).parent().parent().children(".input-file-name").text(e)}),jQuery("#webform-client-form-42 .attach-content .form-managed-file button").text("Upload File"),jQuery(document).ajaxComplete(function(){jQuery("#webform-client-form-42 .attach-content .form-managed-file button").text("Upload File")}),0==jQuery(".view.content-lists").find(".view-content").length&&jQuery(".view.content-lists").addClass("content-lists-empty"),jQuery("#edit-reset").click(function(e){e.preventDefault(),jQuery("#edit-search-api-views-fulltext").val("")}),jQuery(".page-my-page-tracked-companies #edit-company-tag").change(function(){jQuery(".page-my-page-tracked-companies #edit-company-tag1").find("option:first").attr("selected","selected")}),jQuery(".page-my-page-tracked-companies #edit-company-tag1").change(function(){jQuery(".page-my-page-tracked-companies #edit-company-tag").find("option:first").attr("selected","selected")}),jQuery("#views-exposed-form-tracked-companies-page .views-exposed-widgets select").change(function(){var e=jQuery(this).val();jQuery("#views-exposed-form-tracked-companies-page .views-exposed-widgets select").val("All"),jQuery(this).val(e)}),jQuery('input:radio[name="newsletter_type"]').click(function(){"pn"==jQuery(this).attr("value")?jQuery(".form-item-select-user").hide():jQuery(".form-item-select-user").show()})}),jQuery(window).bind("load",function(){var e=0,t=0;e=jQuery(".left-sidebar").outerHeight(),t=jQuery(".content-area").outerHeight(),region_content=jQuery(".region-content").outerHeight();var n=e-(t-region_content);console.log("left"+e),console.log("content"+t),console.log("region_content"+region_content),console.log("new_contentHeight"+n),e>t?(console.log("if"),jQuery(".content-lists, .webform-client-form, .page-user #block-system-main form, .login-upload-page, .content-lists.pr-block").css("min-height",n),jQuery(".content-lists.pr-block").css("min-height",n-10),jQuery(".webform-client-form").css("min-height",n+20),jQuery(".left-sidebar").css("min-height",e)):t>e&&(console.log("else"),jQuery(".left-sidebar").css("min-height",t),jQuery(".content-lists, .webform-client-form, .page-user #block-system-main form").css("min-height",n)),jQuery("#purple-tooltip .purple-button").click(function(){jQuery("#purple-tooltip").addClass("hide-purple"),jQuery("#purple-tooltip").removeClass("show-purple"),jQuery.ajax({type:"post",url:"/ajax/purplebox"})}),jQuery("#purple-tooltip").removeClass("hide-purple"),jQuery("#purple-tooltip").addClass("show-purple"),jQuery(".left-sidebar").wrap('<div class="left-sidebar-wrap"></div>'),jQuery(".left-sidebar-wrap").prepend('<a href="javascript:void(0);" class="left-navbtn glyphicon glyphicon-list"></a><div class="left-sidebar-overlay"></div>'),jQuery("#block-block-1").prepend('<a href="javascript:void(0);" class="inner-btn left-navbtn glyphicon glyphicon-arrow-right"></a>'),jQuery(".left-navbtn").on("click",function(e){e.stopPropagation(),jQuery(".left-sidebar").toggleClass("open-sidebar"),jQuery(".left-sidebar-overlay").toggleClass("left-sidebar-overlay-show"),jQuery(this).addClass("left-arrow"),jQuery(".inner-btn").hasClass("left-arrow")?jQuery(".inner-btn").removeClass("left-arrow"):jQuery(".inner-btn").addClass("left-arrow")}),jQuery(".left-sidebar-overlay").click(function(){jQuery(".left-sidebar").removeClass("open-sidebar"),jQuery(".left-sidebar-overlay").removeClass("left-sidebar-overlay-show"),jQuery(".inner-btn").hasClass("left-arrow")?jQuery(".inner-btn").removeClass("left-arrow"):jQuery(".inner-btn").addClass("left-arrow")}),jQuery("#block-system-main-menu ul.menu").wrap('<div class="menu-wrap"></div>'),jQuery(".menu-wrap").prepend('<a href="javascript:void(0);" class="menu-navbtn glyphicon glyphicon-menu-hamburger"><span>Menu</span></a>'),jQuery(".menu-navbtn").click(function(){jQuery("#block-system-main-menu ul.menu").slideToggle().toggleClass("open-menu")}),jQuery(".pagination").wrap('<div class="responsive-pagination"></div>')});