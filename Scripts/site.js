$(function () {
    $("#header").load("header.html", function() {
        var path = window.location.pathname;
        var page = path.split("/").pop();
        var item = $('a[href="' + page + '"]').first().parent();
        item.addClass("active");
    });
});

function getParameterByName(name) {
    name = name.replace(/[\[]/, "\\[").replace(/[\]]/, "\\]");
    var regex = new RegExp("[\\?&]" + name + "=([^&#]*)"),
        results = regex.exec(location.search);
    return results === null ? "" : decodeURIComponent(results[1].replace(/\+/g, " "));
}